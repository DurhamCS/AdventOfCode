import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    l = [n.strip() for n in f.readlines()]

print(sum([int(l[y][x])+1 for y in range(len(l)) for x in range(len(l[0])) if int(l[y][x]) < min([int(l[y+d[1]][x+d[0]]) for d in ((0,1),(0,-1),(1,0),(-1,0)) if 0<=y+d[1]<len(l) and 0<=x+d[0]<len(l[0])])]))

d = ((0,1),(0,-1),(1,0),(-1,0))
def f(arr):
    if len(arr)>0:
        ra = set()
        for x,y in arr:
            a = [(x+dx,y+dy) for dx,dy in d if 0<=x+dx<len(l[0]) and 0<=y+dy<len(l) and int(l[y][x])<int(l[y+dy][x+dx])<9]
            ra.update(a)
            ra.update(f(a))
        #print(set([int(l[y][x]) for x,y in list(ra)]),len(ra))
        return list(ra)
    return []

mc = []
for y in range(len(l)):
    for x in range(len(l[0])):
        adj = [(x+dx,y+dy) for dx,dy in d if 0<=x+dx<len(l[0]) and 0<=y+dy<len(l)]
        if int(l[y][x]) < min([int(l[ty][tx]) for tx,ty in adj]):
            mc.append((x,y))

mc = sorted([len(f([n]))+1 for n in mc],reverse=True)
mc = mc[:3]
import math
print(math.prod(mc))

