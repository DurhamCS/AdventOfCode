import os
with open(os.path.dirname(__file__)+"/inp.txt") as f:
    l = [n.strip() for n in f.readlines()]
    s = [n for n in l[0]]
    l = [n.split(" -> ") for n in l[2:]]
    l = {k:(k[0]+v,v+k[1]) for k,v in l}
    
from collections import Counter

c = Counter([s[i-1]+s[i] for i in range(1,len(s))])
steps = 40
for _ in range(steps):
    new_c = {k:0 for k in l}
    for k,v in c.items():
        new_c[l[k][0]] += v
        new_c[l[k][1]] += v
    c = new_c
    
l = Counter()
for k,v in new_c.items():
    l[k[0]] += v
    l[k[1]] += v
l[s[0]] += 1
l[s[-1]] += 1
l = sorted([[k,v//2] for k,v in l.items()],key=lambda x:x[1])
print(l[-1][1]-l[0][1])


#NCB, NC:3, CB:3
#N=3, C=6, B=3