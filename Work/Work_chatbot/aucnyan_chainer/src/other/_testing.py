import MeCab
import sys

t = MeCab.Tagger('mecabrc')  # -O chasen, -O wakati, -O yomi, mecabrc
print(t.parse("なんだかんだなのは観たことない"))