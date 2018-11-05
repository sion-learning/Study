# coding: utf-8
import re
import requests
from bs4 import BeautifulSoup
import MeCab
import collections


def get_soup(url):
    resp = requests.get(url)
    soup = BeautifulSoup(resp.content, 'lxml')
    return soup


url_job = "https://www.green-japan.com/job/61027?case=login"
url_company = "https://www.green-japan.com/company/1702?case=login"
url_question = "https://www.green-japan.com/questionnaire/1702?case=login"
url_interview = "https://www.green-japan.com/interview/1702?case=login"
url_pr = "https://www.green-japan.com/pr/1702?case=login"

sp = get_soup(url_job)
extracted_text = []

# url_job テキスト抽出
find_job1 = sp.find("div", attrs={"class": "job-offer-heading"})
extracted_text.append(find_job1.find("div", attrs={"class": "job-offer-icon"}).text)
extracted_text.append(find_job1.h2.text)
extracted_text.append(find_job1.p.text)

find_job2 = sp.find("div", attrs={"class": "job-offer-main-content"})
for line in find_job2.find_all("p"):
    extracted_text.append(line.text)

find_job3 = sp.find_all("table", attrs={"class": "detail-content-table"})
for line in find_job3:
    extracted_text.append(line.text)

# url_company テキスト抽出

# company-description

document_text = []
for line in extracted_text:
    text = re.sub("\n", "", line)
    text = re.sub("\u3000", "", text)
    text = re.sub("\xa0", "", text)
    document_text.append(text)
extracted_text = None

t = MeCab.Tagger('mecabrc')  # -O chasen, -O wakati, -O yomi, mecabrc
result_text = t.parse(" ".join(document_text))
document_text = None

result_words = []
for line in result_text.split("\n"):
    if re.search("名詞", line):
        word = line.split("\t")
        try:
            result_words.append(word[0])
        except IndexError:
            pass
result_text = None

result = collections.Counter(result_words)
result_words = None

for k, v in result.items():
    print(k, v)



"""
# <h1>
# <p>
# <div class="text-section">
# <table class="detail-content-table js-impression"><tr><th>
# <table class="detail-content-table js-impression"><tr><td>
# <table class="detail-content-table js-impression"><tr><td class="pb0"><ul class="search_list pb0"><li>
# <section><h4>
# <section><p>

# sectionの中にhref、他のリンクがあって、そこを再帰的にたどってテキストを取得する
"""