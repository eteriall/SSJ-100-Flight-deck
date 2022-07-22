from os import listdir
from os.path import isfile, join
import os

mypath = os.getcwd()
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
to_remove = tuple(filter(lambda x: x.split(".")[-1].isdigit(), onlyfiles))
for f in to_remove:
    os.remove(f)