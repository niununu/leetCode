import os
from pathlib import Path
import sys

rootFold = os.getcwd()
catch2Dir = "{}/tests/lib/Catch2".format(rootFold)
if Path(catch2Dir).is_dir():
    os.system("git fetch {}".format(catch2Dir))
else:
    catche2Link = "https://github.com/catchorg/Catch2"
    os.system("git clone {} {}".format(catche2Link, catch2Dir))

buildDir = "{}/build".format(rootFold)
if not Path(buildDir).is_dir():
    os.makedirs(buildDir)

os.chdir(buildDir)
if 'darwin' == sys.platform:
    os.system('''cmake .. -G "Xcode"''')
else:
    os.system('''cmake ..''')