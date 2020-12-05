import math


with open('inputs/day3.txt') as f:
    data = f.read().split('\n')


def find_trees(slope):
    x = y = 0
    trees = 0
    while y < len(data):
        trees += data[y][x] == '#'
        x = (x + slope[0]) % len(data[y])
        y += slope[1]

    return trees


print(find_trees((3, 1)))
print(math.prod(find_trees(slope)
                for slope in ((1, 1), (3, 1), (5, 1), (7, 1), (1, 2))))
