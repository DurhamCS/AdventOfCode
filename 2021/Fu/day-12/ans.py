import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    l = [n.strip() for n in f.readlines()]
    l = [n.split("-") for n in l]

def q1(l,cur="start",seen=set()):
    #print(l,cur,seen)
    if cur != "end":
        if cur == cur.lower():
            seen.add(cur)
        adj = set([k if v==cur else v for k,v in l if k==cur or v==cur])
        adj = adj - (adj & seen)
        return sum([q1(l, n, seen | set([n] if n==n.lower() else [])) for n in adj])
    else:
        return 1

tot = set()
def q2(l,cur="start",seen={"start":1},curs=None,curss="start"):
    if cur != "end":
        if cur == cur.lower():
            if cur in seen: seen[cur] += 1
            else: seen[cur] = 1
        adj = set([k if v==cur else v for k,v in l if k==cur or v==cur])
        ta = set([k for k,v in seen.items() if v>=1])
        if curs is not None and curs in ta and seen[curs]==1:
            ta.remove(curs)
        adj = adj - (adj & ta)
        c = 0
        for n in adj:
            if curs is None and n == n.lower():
                c += q2(l, n, seen.copy(), n, curss+n)
                c += q2(l, n, seen.copy(), None, curss+n)
            else:
                c += q2(l, n, seen.copy(), curs, curss+n)
        return c
    else:
        tot.add(curss)
        return 1



#print(q1(l))
print(q2(l))
print(len(tot))