import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:    
    lines = f.readlines()
    lines = [n.strip() for n in lines]
    lines = [n.split("->") for n in lines]
    lines = [[n[0].strip().split(","),n[1].strip().split(",")] for n in lines]
    lines = [[[int (j) for j in m] for m in n] for n in lines]
    

L = [[n for n in lines if n[0][0]==n[1][0] or n[0][1]==n[1][1]],lines]
for i,l in enumerate(L):
    seen = dict()
    for n in l:
        [[x1,y1],[x2,y2]] = n
        #vert
        if x1==x2:
            ca = [[x1,dy] for dy in range(min(y1,y2),max(y1,y2)+1)]
        #hori
        elif y1==y2:
            ca = [[dx,y1] for dx in range(min(x1,x2),max(x1,x2)+1)]
        #diag
        else:
            v = [1 if x1>x2 else -1,1 if y1>y2 else -1]
            ca = [[x1,y1]]
            while ca[-1] != [x2,y2]:
                ca.append([ca[-1][0]-v[0],ca[-1][1]-v[1]])
        for m in ca:
            m = tuple(m)
            if m not in seen: seen[m] = 1
            else: seen[m] += 1
    print(f"q{i+1}: {sum([v > 1 for v in seen.values()])}")

