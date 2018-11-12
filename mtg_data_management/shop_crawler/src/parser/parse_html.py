# coding: UTF-8

import re


def get_category_list(html):
    r = re.compile("/[0-9a-zA-Z]{3}\)|\([0-9a-zA-Z]{3}\)")

    category_list = []
    for line in html.find(id='content').find_all('li'):
        line = str(line)
        m = r.search(line)
        if m:
            category_list.append(m.group(0).strip("(/)"))

    return category_list
