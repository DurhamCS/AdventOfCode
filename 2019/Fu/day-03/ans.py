import os
with open(os.path.dirname(__file__)+"/inp.txt") as f:
    lines = [n.strip() for n in f.readlines()]
d = {"R":[1,0],"L":[-1,0],"U":[0,1],"D":[0,-1]}
lines = [[[m[0],int(m[1:])] for m in n.split(",")] for n in lines]

def q1(lines,d):
    c = set()
    cur = (0,0)
    for di,n in lines[0]:
        for i in range(n):
            cur = tuple([cur[i]+d[di][i] for i,n in enumerate(cur)])
            c.add(cur)
    cur = (0,0)
    inter = set()
    for di,n in lines[1]:
        for i in range(n):
            cur = tuple([cur[i]+d[di][i] for i,n in enumerate(cur)])
            if cur in c: inter.add(cur)

    l = 10**20
    for a,b in inter:
        d = abs(a)+abs(b)
        l = min(l,d)
    print(l)

q1(lines,d)

c = dict()
cur = (0,0)
s = 0
for di,n in lines[0]:
    for i in range(n):
        cur = tuple([cur[i]+d[di][i] for i,n in enumerate(cur)])
        s += 1
        if cur not in c: c[cur] = s
cur = (0,0)
inter = dict()
s = 0
for di,n in lines[1]:
    for i in range(n):
        cur = tuple([cur[i]+d[di][i] for i,n in enumerate(cur)])
        s += 1
        if cur in c:
            if cur not in inter: inter[cur] = s + c[cur]

print(min([n for n in inter.values()]))