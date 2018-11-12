# coding: utf-8

import datetime
from os import mkdir
from pathlib import Path

data_storage = "/../resource/data_storage/"

# pre-process
time = datetime.datetime.today()
start_time = time.strftime("%Y-%m-%d_%H-%M-%S")
print("crawling started at: " + str(time))

dst_directory = str(Path.cwd()) + data_storage + start_time + "/"
mkdir(dst_directory)

with open():


# finish
time = datetime.datetime.today()
print("parsing finished at: " + str(time))
