import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    lines = f.readlines()
    lines = [n.strip() for n in lines]
    bn = [int(n) for n in lines[0].split(",")]
    lines = [[int(m) for m in n.split(" ") if m!=""] for n in lines[1:] if n!=""]
    fl = []
    for i in range(0,len(lines),5):
        a = []
        for j in range(i,i+5):
            for n in lines[j]:
                a.append(n)
        fl.append(a)
    sum_arr = [sum([sum(lines[j]) for j in range(i,i+5)]) for i in range(0,len(lines),5)]

w = False
for b in bn:
    for i,n in enumerate(fl):
        if b in n:
            fl[i][fl[i].index(b)] = -1
            sum_arr[i] -= b
            #x
            if -5 in [sum(n[i*5:(i+1)*5]) for i in range(5)]:
                w = True; break
            #y
            elif -5 in [sum([n[i+j*5] for j in range(5)]) for i in range(5)]:
                w = True; break
    if w:
        break
print(sum_arr[i]*b)

w = None
won = set()
for b in bn:
    for i,n in enumerate(fl):
        if i not in won and b in n:
            fl[i][fl[i].index(b)] = -1
            sum_arr[i] -= b
            #x
            if -5 in [sum(n[i*5:(i+1)*5]) for i in range(5)]:
                w = i; won.add(i)
            #y
            elif -5 in [sum([n[i+j*5] for j in range(5)]) for i in range(5)]:
                w = i; won.add(i)
    if len(won)==len(fl): break
print(sum_arr[w]*b)