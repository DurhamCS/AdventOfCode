import os
with open(os.path.dirname(__file__)+"/inp.txt") as f:
    l = [int(n) for n in f.readline().split(",")]

"""
l[1] = 12
l[2] = 2

i = 0
while i<len(l):
    if l[i] == 1:
        l[l[i+3]] = l[l[i+1]] + l[l[i+2]]
    elif l[i] == 2:
        l[l[i+3]] = l[l[i+1]] * l[l[i+2]]
    else: break
    i += 4
print(l[0])"""

def f(L):
    for k in range(100):
        for j in range(100):
            l = L[:]
            l[1] = k
            l[2] = j
            i = 0
            while i<len(l):
                if l[i] == 1:
                    l[l[i+3]] = l[l[i+1]] + l[l[i+2]]
                elif l[i] == 2:
                    l[l[i+3]] = l[l[i+1]] * l[l[i+2]]
                else: break
                i += 4
            if l[0] == 19690720:
                return k,j

k,j = f(l)
print(100*k+j)