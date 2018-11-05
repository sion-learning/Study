# coding:utf-8
from __future__ import absolute_import
from __future__ import unicode_literals
import chainer.links as L
import chainer.functions as F
import chainer
import numpy as np
from chainer import reporter


class Seq2Seq(chainer.Chain):
    def __init__(self, input_words):
        super(Seq2Seq, self).__init__(
            word_vec=L.EmbedID(input_words, 300),
            input_vec=L.LSTM(300, 300),
            output_vec=L.LSTM(300, 300),
            output_word=L.Linear(300, input_words)
        )
        self.train = True

    def encode(self, sentence):
        c = None
        for word in sentence:
            x = np.array([word], dtype=np.int32)
            h = F.tanh(self.word_vec(x))
            c = self.input_vec(h)
        return c

    def decode(self, vector=None, targer_sentence=None, dictionary=None):
        loss = 0
        if self.train:
            for index, target_word in enumerate(targer_sentence):
                if index == 0:
                    j = F.tanh(self.output_vec(vector))
                    pred_word = self.output_word(j)
                else:
                    j = F.tanh(self.output_vec(j))
                    pred_word = self.output_word(j)
                loss += F.softmax_cross_entropy(pred_word, np.array([target_word], dtype=np.int32))
            return loss
        else:
            gen_sentence = []
            cnt = 0
            while True:
                if cnt == 0:
                    j = F.tanh(self.output_vec(vector))
                    pred_word = self.output_word(j)
                else:
                    j = F.tanh(self.output_vec(j))
                    pred_word = self.output_word(j)
                id = np.argmax(pred_word.data)
                cnt += 1
                word = dictionary[id]
                if word == "<eos>":
                    return gen_sentence

                gen_sentence.append(word)
                if cnt == 100:
                    break
            return gen_sentence

    def generate_sentence(self, sentence, dictionary):
        self.initialize()
        encode_vector = self.encode(sentence=sentence)
        return self.decode(vector=encode_vector, dictionary=dictionary)

    def initialize(self):
        self.input_vec.reset_state()
        self.output_vec.reset_state()

    def __call__(self, sentence, target_sentence):
        self.initialize()
        encode_vector = self.encode(sentence=sentence)
        self.loss = None
        self.loss = self.decode(vector=encode_vector, targer_sentence=target_sentence)
        reporter.report({'loss': self.loss}, self)

        return self.loss