import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    lines = f.readlines()
    lines = [n.split() for n in lines]
    
a = [[0,-int(n[1])] if n[0]=="up" else [0,int(n[1])] if n[0]=="down" else [int(n[1]),0] for n in lines]
print(sum([n[0] for n in a])*sum([n[1] for n in a]))

aim = 0
d = 0
for dx,da in a:
    aim += da
    d += aim*dx

print(sum([dx for dx,da in a])*sum([d]))