import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    l = [n.strip() for n in f.readlines()]
    folds = [n[11:] for n in l[l.index("")+1:]]
    l = [n.split(",") for n in l[:l.index("")]]
    l = [[int(m) for m in n] for n in l]
    folds = [[int(n[2:]),None] if n[0] == "x" else [None,int(n[2:])] for n in folds]

def vis(l,mc):
    grid = [["." for _ in range(mc[0])] for k in range(mc[1])]
    for x,y in l:
        grid[y][x] = "#"
    for n in grid:
        print("".join(n))
    print()

mc = [[11,7],[5,7]]

for _,f in enumerate(folds):
    if f[0] is None: #vert, at y=f[1]
        l = [[x,y] for x,y in l if y!=f[1]]
        for i,n in enumerate(l):
            if n[1] > f[1]:
                r = (n[1]-f[1])*2 #+1
                l[i][1] -= r
    else: #hori, at x=f[0]
        l = [[x,y] for x,y in l if x!=f[0]]
        for i,n in enumerate(l):
            if n[0] > f[0]:
                r = (n[0]-f[0])*2 #+1
                l[i][0] -= r
    l = list(set([(x,y) for x,y in l]))
    l = [[x,y] for x,y in l]
    #vis(l,mc[_])
    print(len(l))
mc = [max([n[0] for n in l])+1,max(n[1] for n in l)+1]
vis(l,mc)
    
"""
- - * - -   - - * - -   - - - - -
- - - - -   # # # # #   - - - - -
# # # # #   - - * - -   - - * - -
- - - - -   - - - - -   # # # # #
- - * - -   - - - - -   - - * - -
mc = 4      
f[1] = 2    f[1] = 1    f[1] = 3
y = 4 > 0   y = 2 > 0   y = 4 > 2
"""