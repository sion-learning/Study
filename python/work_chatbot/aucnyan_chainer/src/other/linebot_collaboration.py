#!/usr/bin/env python
# coding: utf-8

from gae_http_client import RequestsHttpClient

from google.appengine.api import taskqueue

from google.appengine.ext import vendor

import sys
import config
import urllib2
import json

#ライブラリを読み込むため
vendor.add('lib')

from flask import Flask, request, abort

from linebot import (
    LineBotApi, WebhookHandler
)
from linebot.exceptions import (
    InvalidSignatureError
)
from linebot.models import (
    MessageEvent, TextMessage, TextSendMessage
)

from linebot.models import ImageSendMessage



#AUCFAN APIを使うためのトークン
api_token = config.AUCFAN_TOKEN
api_secret_token = config.AUCFAN_SECRET_TOKEN

app = Flask(__name__)


#Line bot api を使うためのトークン
line_bot_api = LineBotApi(config.CHANNEL_ACCESS_TOKEN, http_client=RequestsHttpClient)
handler = WebhookHandler(config.CHANNEL_SECRET)

def get_product_data(user_message):
    url = 'https://api.aucfan.com/search/v2/item/list?token=8c187ebda20e43a941b00baa69b33d92&stoken=VkRCYWtZVXU1WldjSFZhb1dscFpqaVNGWmhiazB4Y0hCcWFWZEdXbWhoVm5CSVkwVmFjV0ZWTVhGUmJXaGhWa1pHTmxrd1pFWk9WMFpWVlZob1dtRnJSak5YVnpGSFlVVTFjV0pIYkU1bGF6VnlWREZTU21WVk1VVlNWRkpPVWtaR05GUlhjRVprTURGeFVWaHNUMkpWV1hoWFZFcGhZVWRLZEZWdWNHbE5ibU01&search='+user_message
    response = urllib2.urlopen(url)
    product_data = json.loads(response.read())
    reply_messages = ''
    if product_data['hit_count'] > 0:
        for data in product_data['items']:
            reply_messages = u'商品名:' + '\n' + data['title'] + '\n\n'
            reply_messages += u'値段:' + '\n' + str(data['price']) + u'円' + '\n\n'
             reply_messages += u'商品URL:' + '\n' + data['siteurl'] + '\n\n'
            reply_messages += u'写真:' + '\n' + data['thumbnail'] + '\n\n'
    else: #商品がなかった場合
        reply_messages = '商品が見つかりませんでした。'
    return reply_messages


#画像メッセージ関数
def make_image_message(user_message):
    url = 'https://api.aucfan.com/search/v2/item/list?token=8c187ebda20e43a941b00baa69b33d92&stoken=VkRCYWtZVXU1WldjSFZhb1dscFpqaVNGWmhiazB4Y0hCcWFWZEdXbWhoVm5CSVkwVmFjV0ZWTVhGUmJXaGhWa1pHTmxrd1pFWk9WMFpWVlZob1dtRnJSak5YVnpGSFlVVTFjV0pIYkU1bGF6VnlWREZTU21WVk1VVlNWRkpPVWtaR05GUlhjRVprTURGeFVWaHNUMkpWV1hoWFZFcGhZVWRLZEZWdWNHbE5ibU01&search='+user_message
    response = urllib2.urlopen(url)
    product_data = json.loads(response.read())
    reply_messages = ''
    if product_data['hit_count'] > 0:
        messages = ImageSendMessage(
                original_content_url = data['thumbnail'],
                preview_image_url = data['thumbnail']
                )
    else:
        reply_messages = '商品が見つかりませんでした。'
    return messages


@app.route("/callback", methods=['POST'])
def callback():
    # get X-Line-Signature header value
    signature = request.headers['X-Line-Signature']
    # get request body as text
    body = request.get_data(as_text=True)
    app.logger.info("Request body: " + body)

    # Task Queue Add
    taskqueue.add(url='/worker',
                  params={'body': body,
                          'signature': signature},
                  method="POST")

    return 'OK'
@app.route("/worker", methods=['POST'])
def worker():
    body = request.form.get('body')
    signature = request.form.get('signature')

    # handle webhook body
    try:
        handler.handle(body, signature)
    except InvalidSignatureError:
        abort(400)
    return 'OK'

@handler.add(MessageEvent, message=TextMessage)
def handle_message(event):
    text_message = event.message.text
    reply_messages = get_product_data(text_message)
    #画像をメッセージで送る処理
    #messages = make_image_message()
    #line_bot_api.reply_message(
    #        event.reply_token,
    #        messages
    #        )
    line_bot_api.reply_message(
        event.reply_token,
        TextSendMessage(text=reply_messages))
if __name__ == "__main__":
    app.run()