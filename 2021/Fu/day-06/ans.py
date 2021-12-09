import os
from collections import Counter as C
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    lines = [int(n) for n in f.readline().split(",")]

a = [0]*9
for k,v in C(lines).items():
    a[k] = v

days = 256

for _ in range(days):
    b = [0]*9
    b[6] = a[0]
    b[8] = a[0]
    for i in range(1,9):
        b[i-1] += a[i]
    a = b[:]

print(sum(a))