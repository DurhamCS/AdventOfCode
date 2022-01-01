import os
l = [l.strip() for l in open(os.path.dirname(__file__)+"/inp.txt").readlines()]
l = [[int(m) for m in n] for n in l]
neighbour = [[0,1],[0,-1],[1,0],[-1,0]]

def f():
    q = set()
    dist = dict() #dist from source to u = dist[u]

    for y in range(len(l)):
        for x in range(len(l[0])):
            q.add((y,x))
    dist[(0,0)] = 0

    while len(list(q)) > 0:
        u = min([[k,v] for k,v in dist.items() if k in q],key=lambda x:x[1])[0]
        if u == (len(l)-1,len(l[0])-1): break
        q.remove(u)
        d = dist[u]
        del dist[u]
        nei = [(u[0]+dy,u[1]+dx) for dx,dy in neighbour if 0<=u[0]+dy<len(l) and 0<=u[1]+dx<len(l[0]) and (u[0]+dy,u[1]+dx) in q]
        for n in nei:
            alt = d + l[n[0]][n[1]]
            if n not in dist or alt < dist[n]:
                dist[n] = alt
                
    return dist

#q1
print(f()[(len(l)-1,len(l[0])-1)])

"""
3 -> 0, 6 -> 3
4 -> 1
5 -> 2
10 -> 7
"""
#q2
my,mx = len(l),len(l[0])
t = [["" for i in range(mx*5)] for _ in range(my*5)]
for ty in range(5):
    for tx in range(5):
        for y in range(ty*my,(ty+1)*my):
            for x in range(tx*mx,(tx+1)*mx):
                if tx == 0 and ty == 0:
                    t[y][x] = l[y][x]
                elif tx == 0:
                    t[y][x] = t[y-my][x] + 1
                    if t[y][x] == 10:
                        t[y][x] = 1
                else:
                    t[y][x] = t[y][x-mx] + 1
                    if t[y][x] == 10:
                        t[y][x] = 1

l = t
print(f()[(len(l)-1,len(l[0])-1)])