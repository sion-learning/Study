# coding:utf-8
import MeCab
from aucnyan_chainer.src.model import Seq2Seq
from chainer import training
import chainer
from chainer.training import extensions
import numpy as np
import sys
import codecs
import json

from slackbot.bot import default_reply
from slackbot.bot import Bot
from slackbot.bot import respond_to
from slackbot.bot import listen_to

sys.stdout = codecs.getwriter('utf_8')(sys.stdout)
tagger = MeCab.Tagger('mecabrc')


def parse_sentence(sentence):
    parsed = []
    for chunk in tagger.parse(sentence).splitlines()[:-1]:
        # (surface, feature) = chunk.split('\t')
        chunk_list = chunk.split('\t')
        surface = chunk_list[0]
        # parsed.append(surface.decode("utf-8"))
        parsed.append(surface)
    return parsed


def parse_file(filename):
    questions = []
    answers = []
    with open(filename, "r", encoding='utf_8') as f:
        lines = f.readlines()

        for line in lines:
            sentences = line.split("\t")
            question = ["<start>"] + parse_sentence(sentences[0]) + ["<eos>"]
            answer = parse_sentence(sentences[1]) + ["<eos>"]
            questions.append(question)
            answers.append(answer)
    word2id = {"■": 0}
    id2word = {0: "■"}
    id = 1

    sentences = questions + answers
    for sentence in sentences:
        for word in sentence:
            if word not in word2id:
                word2id[word] = id
                id2word[id] = word
                id += 1

    return questions, answers, word2id, id2word


def sentence_to_word_id(split_sentences, word2id):
    id_sentences = []
    for sentence in split_sentences:
        ids = []
        for word in sentence:
            id = word2id[word]
            ids.append(id)
        id_sentences.append(ids)
    return id_sentences


class ParallelSequentialIterator(chainer.dataset.Iterator):
    def __init__(self, dataset, batch_size, repeat=True):
        self.dataset = dataset
        self.batch_size = batch_size  # batch size
        self.epoch = 0
        self.is_new_epoch = False
        self.repeat = repeat
        self.iteration = 0
        self.epoch_detail = 0

    def __next__(self):
        length = len(self.dataset[0])
        if not self.repeat and self.iteration * self.batch_size >= length:
            raise StopIteration

        batch_start_index = self.iteration * self.batch_size % length
        batch_end_index = min(batch_start_index + self.batch_size, length)

        questions = [self.dataset[0][batch_index] for batch_index in range(batch_start_index, batch_end_index)]
        answers = [self.dataset[1][batch_index]for batch_index in range(batch_start_index, batch_end_index)]

        self.iteration += 1

        epoch = self.iteration * self.batch_size // length
        self.is_new_epoch = self.epoch < epoch
        if self.is_new_epoch:
            self.epoch = epoch
            self.epoch_detail = self.epoch

        return list(zip(questions, answers))


class BPTTUpdater(training.StandardUpdater):
    def update_core(self):
        loss = 0
        train_iter = self.get_iterator('main')
        optimizer = self.get_optimizer('main')

        batch = train_iter.__next__()
        for question, answer in batch:
            loss += optimizer.target(np.array(question, dtype=np.int32),
                                     np.array(answer, dtype=np.int32))

        optimizer.target.cleargrads()
        loss.backward()
        loss.unchain_backward()
        optimizer.update()


if __name__ == '__main__':
    # questions, answers, word2id, id2word = parse_file("../data/conversation_data.txt")
    questions, answers, word2id, id2word = parse_file("../data/Hestia.txt")
    ids_questions = sentence_to_word_id(questions, word2id=word2id)
    ids_answers = sentence_to_word_id(answers, word2id=word2id)

    model = Seq2Seq(len(word2id))
    optimizer = chainer.optimizers.Adam()
    optimizer.setup(model)

    epoch_num = 100  # ここの数を調節する
    train_iter = ParallelSequentialIterator(dataset=(ids_questions, ids_answers), batch_size=epoch_num)

    updater = BPTTUpdater(train_iter, optimizer)
    trainer = training.Trainer(updater, (epoch_num, 'epoch'))

    trainer.extend(extensions.PrintReport(['epoch', 'iteration', 'main/loss']), trigger=(100, 'iteration'))
    trainer.extend(extensions.LogReport())
    trainer.run()

    chainer.serializers.save_npz("./dic/model.npz", model)
    json.dump(id2word, open("./dic/dictionary_i2w.json", "w"))
    json.dump(word2id, open("./dic/dictionary_w2i.json", "w"))
