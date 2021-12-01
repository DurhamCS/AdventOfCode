import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    lines = f.readlines()
    lines = [int(n.strip()) for n in lines]
    
print(sum([1 for i in range(1,len(lines)) if lines[i]>lines[i-1]]))

t = [sum(lines[i-2:i+1]) for i in range(2,len(lines))]
print(sum([1 for j in range(1,len(t)) if t[j]>t[j-1]]))