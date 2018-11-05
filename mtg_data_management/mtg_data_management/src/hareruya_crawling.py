# coding: utf-8

import re
import datetime
from os import mkdir
from time import sleep
from pathlib import Path

from mtg_data_management.src.crawler import crawl_html as gh
from mtg_data_management.src.parser import parse_html as gc
from mtg_data_management.src.saver import save_crawled_file as sf

sleep_time = 10
target_rarity = "R"  # B,R,U,C,F,T,L,PRE,PW,S,M,L,ES,EX
data_storage = "/../resource/data_storage/"
category_url = "http://mtgwiki.com/wiki/%E3%82%AB%E3%83%BC%E3%83%89%E3%82%BB%E3%83%83%E3%83%88%E4%B8%80%E8%A6%A7"


def create_item_url(category, directory, rarity, num):
    num = num + 1
    path = directory + category + "-R_p" + str(num) + ".html"
    url = "http://www.hareruyamtg.com/jp/c/c" + line + "-" + rarity + "_p" + str(num) + "/"

    return url, path, num


def get_item_from_html(url, sec):
    sleep(sec)
    html = gh.get_html_soup(url).find(id="category_item")

    return html


# pre-process
time = datetime.datetime.today()
start_time = time.strftime("%Y-%m-%d_%H-%M-%S")
print("crawling started at: " + str(time))

dst_directory = str(Path.cwd()) + data_storage + start_time + "/"
mkdir(dst_directory)

page_num = 0
r = re.compile("([0-9]+)ページ中[0-9]+ページ目")

# get category
category_html = gh.get_html_soup(category_url)
category_list = gc.get_category_list(category_html)
print("category list: ", category_list)

category_list = ['DTK']

# crawling and save
for line in category_list:
    item_url, dst_path, page_num = create_item_url(line, dst_directory, target_rarity, page_num)

    print("processing: ", item_url)
    item_html = get_item_from_html(item_url, sleep_time)

    if item_html:
        sf.extract_html_to_file(item_html, dst_path)
        print("processed : ", item_url)

        find_result = item_html.find(class_="result_pagenum")
        m = r.search(str(find_result)).group(1)
        max_page_num = int(m)

        for i in range(max_page_num - 1):

            item_url, dst_path, page_num = create_item_url(line, dst_directory, target_rarity, page_num)

            print("processing: ", item_url)
            item_html = get_item_from_html(item_url, sleep_time)

            sf.extract_html_to_file(item_html, dst_path)
            print("processed : ", item_url)

    else:
        print("not processed: ", item_url)

# finish
time = datetime.datetime.today()
print("crawling finished at: " + str(time))
