import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    lines = f.readlines()
    lines = [n.strip() for n in lines]
    
l = [0]*len(lines[0])
for m in lines:
    for i,n in enumerate(m):
        if int(n): l[i]+=1
        else: l[i]-=1
l = "".join(["1" if n>0 else "0" for n in l])
print(int(l,2)*int("".join(["0" if int(n)>0 else "1" for n in l]),2))

o = []
A = lines[:]
for i in range(len(A[0])):
    a = [m[i] for j,m in enumerate(A)]
    if len(a)==1: break
    if a.count("1") >= a.count("0"):
        o.append("1")
        A = [n for n in A if n[i]=="1"]
    else:
        o.append("0")
        A = [n for n in A if n[i]=="0"]

c = []
A = lines[:]
for i in range(len(A[0])):
    a = [m[i] for j,m in enumerate(A)]
    if len(a)==1:
        c = A[0]
        break
    if a.count("1") < a.count("0"):
        c.append("1")
        A = [n for n in A if n[i]=="1"]
    else:
        c.append("0")
        A = [n for n in A if n[i]=="0"]

print(int("".join(o),2)*int("".join(c),2))