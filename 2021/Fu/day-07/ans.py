import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    l = [int(n) for n in f.readline().split(",")]

print(min([sum([abs(n-x) for n in l]) for x in range(min(l),max(l))]))

print(min([sum([(abs(n-x)**2+abs(n-x))/2 for n in l]) for x in range(min(l),max(l))]))