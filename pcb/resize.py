import sys
import re

scale = float(sys.argv[3])

def scalexy(val):
    x = float(val.group(1)) * scale
    y = float(val.group(2)) * scale
    return '(xy {} {})'.format(x, y)

with open(sys.argv[1], 'r') as in_file, open(sys.argv[2], 'w', newline='') as out_file:
    for line in in_file:
        line = re.sub(r'\(xy ([0-9-.]+) ([0-9-.]+)\)', scalexy, line)
        out_file.write(line)