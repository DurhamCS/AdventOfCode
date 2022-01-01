import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    l = [n.strip() for n in f.readlines()]
    l = [[int(m) for m in n] for n in l]

adj = [(0,1),(1,0),(0,-1),(-1,0),(1,1),(-1,-1),(-1,1),(1,-1)]

def q1(l):
    c = 0
    step = 100
    for _ in range(step):
        fl = []
        for y in range(len(l)):
            for x in range(len(l[0])):
                l[y][x] += 1
                if l[y][x] == 10:
                    l[y][x] = 0
                    c += 1
                    fl.append((x,y))
        seen = set(fl)
        while len(fl) > 0:
            x,y = fl.pop(0)
            seen.add((x,y))
            t = [(x+dx,y+dy) for dx,dy in adj if 0<=x+dx<10 and 0<=y+dy<10 and l[y+dy][x+dx]!=0]
            for tx,ty in t:
                l[ty][tx] += 1
                if l[ty][tx] == 10:
                    l[ty][tx] = 0
                    fl.append((tx,ty))
                    c += 1
                    seen.add((ty,tx))
    print(c)

def q2(l):
    c = 0
    step = 0
    while True:
        fl = []
        for y in range(len(l)):
            for x in range(len(l[0])):
                l[y][x] += 1
                if l[y][x] == 10:
                    l[y][x] = 0
                    c += 1
                    fl.append((x,y))
        seen = set(fl)
        while len(fl) > 0:
            x,y = fl.pop(0)
            seen.add((x,y))
            t = [(x+dx,y+dy) for dx,dy in adj if 0<=x+dx<10 and 0<=y+dy<10 and l[y+dy][x+dx]!=0]
            for tx,ty in t:
                l[ty][tx] += 1
                if l[ty][tx] == 10:
                    l[ty][tx] = 0
                    fl.append((tx,ty))
                    c += 1
                    seen.add((ty,tx))
        step += 1
        if sum([sum([m for m in n]) for n in l]) == 0:
            break
    print(step)

q2(l)