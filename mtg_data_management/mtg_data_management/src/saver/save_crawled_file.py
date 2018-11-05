# coding: utf-8


def extract_html_to_file(html, path):
    with open(path, mode='wb') as f:
        f.write(html.encode('CP932'))

    return None
