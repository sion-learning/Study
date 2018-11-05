# coding: utf-8
import re
import requests
from bs4 import BeautifulSoup


def get_soup(url):
    resp = requests.get(url)
    soup = BeautifulSoup(resp.content, 'lxml')
    return soup


def pull_category(sp):
    category = str(sp.find_all("div", attrs={"class": "menuBox01"})).split("\n")
    pattern = re.compile('\<a.+\"\>(.+)\<span\>', re.IGNORECASE)
    category_list = [pattern.search(line).group(1) for line in category if pattern.search(line) is not None]
    return str(" ".join(category_list))


# 価格.com
def scraping_page(url, result, depth, url_head):
    print("processing...", url[1], "depth on {}".format(depth))
    line = str("\t" * depth + url[1])
    result.append(line)
    sp = get_soup(url[0])

    try:
        html = str(sp.find_all("ul", attrs={"class": "c-list1"})).split("\n")

        if html == ['[]']:
            result.append("\t" * (depth + 1) + pull_category(sp))
            url_title = None
        else:
            pattern = re.compile('href\=\"(.+)\"', re.IGNORECASE)
            url_list = [url_head + pattern.search(line).group(1) for line in html if pattern.search(line) is not None]

            pattern = re.compile('\<a.+\"\>(.+)\<\/a\>', re.IGNORECASE)
            title_list = [pattern.search(line).group(1) for line in html if pattern.search(line) is not None]

            url_title = list(zip(url_list, title_list))

            line = str("\t" * depth + url[1])
            result.append(line)

        for site in url_title:
            scraping_page(site, result, depth+1, url_head)

    except:
        pass

    return result


result = []
url_head = "http://kakaku.com"
url_top = ["http://kakaku.com/kaden/", "家電"]
final_result = scraping_page(url_top, result, 0, url_head)
print(final_result)

with open('output/kakakucom.tsv', 'w') as f:
    for row in final_result:
        f.write(row + "\n")
