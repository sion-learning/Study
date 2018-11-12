# encoding; utf-8

from src.crawler import get_html as gh

html = gh.get_html_soup("http://www.hareruyamtg.com/jp/c/cGRN-R/")

print(html)