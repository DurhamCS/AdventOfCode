import math
import itertools


with open('day1.txt') as f:
    lines = list(int(val) for val in f.readlines())


for i in (2, 3):
    for combination in set(itertools.combinations(lines, i)):
        if sum(combination) == 2020:
            print(math.prod(combination))
            break
