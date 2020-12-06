with open("inputs/day6.txt") as f:
    data = [group.split() for group in f.read().split('\n\n')]


def get_intersections(group):
    cur = set(group[0])
    for answer in group:
        cur &= set(answer)

    return len(cur)


print(sum(len(set(''.join(group))) for group in data))
print(sum(get_intersections(group) for group in data))
