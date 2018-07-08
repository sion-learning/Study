# coding:utf-8
import MeCab
import codecs
from slackbot.bot import default_reply
from slackbot.bot import Bot
from slackbot.bot import respond_to
from slackbot.bot import listen_to
from aucnyan_chainer.src.model import Seq2Seq
import chainer
import json
import sys

sys.stdout = codecs.getwriter('utf_8')(sys.stdout)
tagger = MeCab.Tagger('mecabrc')

id2word = json.load(open("./dic/dictionary_i2w.json", "r"))

id2word = {int(key): value for key, value in id2word.items()}
word2id = json.load(open("./dic/dictionary_w2i.json", "r"))
model = Seq2Seq(len(word2id))
chainer.serializers.load_npz("./dic/model.npz", model)
model.train = False


@respond_to("おやつ")
def mention_message(message):
    message.reply('ケーキなどいかがですか。')


@listen_to("パンケーキ")
def listen_message(message):
    message.reply('私を呼びましたかな？')


@default_reply
def reply_message(message):
    parsed_sentence = []
    try:
        parsed = tagger.parse(message.body["text"])
        parsed = parsed.splitlines()[:-1]
        # メッセージ確認用 message.reply(parsed[0])
        for chunk in parsed:
            # メッセージ確認用 message.reply(chunk)
            # (surface, feature) = chunk.decode("utf-8").split('\t')
            chunk_list = chunk.split('\t')
            surface = chunk_list[0]
            # メッセージ確認用 message.reply(surface)
            parsed_sentence.append(surface)
        parsed_sentence = ["<start>"] + parsed_sentence + ["<eos>"]

        ids = []
        for word in parsed_sentence:
            if word in word2id:
                id = word2id[word]
                ids.append(id)
            else:
                ids.append(0)
        ids_question = ids
        sentence = "".join(model.generate_sentence(ids_question, dictionary=id2word)).encode("utf-8")

        # 動作不明いったんコメントアウト sentence = sentence.replace("○", "user")
        message.reply(sentence)
    except Exception as e:
        print(str(e))
        message.reply("解析できなかったのでもう一度おねがいします。")


def main():
    bot = Bot()
    bot.run()


if __name__ == "__main__":
    main()
