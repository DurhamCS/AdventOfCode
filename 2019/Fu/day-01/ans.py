import os
with open(os.path.dirname(__file__)+"/inp.txt") as f:
    lines = [int(n.strip()) for n in f.readlines()]
import math

print(sum([math.floor(n/3)-2 for n in lines]))

s = 0
for i,n in enumerate(lines):
    while True:
        lines[i] = math.floor(lines[i]/3)-2
        s += lines[i]
        if lines[i]/3 < 2: break
print(s)