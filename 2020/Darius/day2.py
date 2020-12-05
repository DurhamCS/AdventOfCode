with open('inputs/day2.txt') as f:
    lines = [(list(map(int, line.split(' ')[0].split('-'))),
              line.split(' ')[1].split(':')[0],
              line.split(' ')[2])
             for line in f.readlines()]


print(sum(minmax[0] <= data.count(letter) <= minmax[1] for minmax, letter, data in lines))
print(sum((sum(data[position-1] == letter for position in minmax) == 1 for minmax, letter, data in lines)))
