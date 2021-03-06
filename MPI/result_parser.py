import re
import sys

file = open(sys.argv[1])
results = list()

class Helper:
    def __init__(self, mode):
        self.mode = mode
        self.data = dict()

for line in file:
    some = re.match(r'Mode.*(\d)', line)

    if (some != None):
        helper = Helper(int( some.group(1))) 
        results.append(helper)
    else:
        some = re.match(r'\[(\d+).+?([0-9]+\.[0-9]+)', line)
        results[-1].data[int(some.group(1))] = some.group(2)
file.close()

for x in range(100, 2001, 100):
    s = "\hline " + str(x)
    for elem in results:
        s = s + " & " + elem.data[x]
    s = s + " \\\\"
    print(s)

for elem in results:
    s = str(elem.mode) + " threads:\n"
    for x in range(100,2001,100):
        s = s + "(" + str(x) + ", " + elem.data[x] + ")"
    print(s)
