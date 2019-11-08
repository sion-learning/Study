# coding: utf-8

from bs4 import BeautifulSoup as bSoup
import urllib.request as req


def get_html_soup(url):
    res = req.urlopen(url)

    try:
        soup = bSoup(res, 'lxml')
    except:
        soup = bSoup(res, 'html5lib')

    return soup
