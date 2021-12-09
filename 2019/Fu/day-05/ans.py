import os
with open(os.path.dirname(__file__)+"/inp.txt") as f:
    l = [int(n) for n in f.readline().split(",")]

def q(l):
    i = 0
    while i<len(l) and l[i]!=99:
        s = str(l[i])
        if s[-1] in {"3","4"}:
            a = i+1 if len(s)>1 else  l[i+1]
            if s[-1] == "3":
                l[a] = 5 #user inp
                i += 2
            else:
                print(l[a])
                i += 2
        else:
            if len(s) == 1: "0"+s
            ins = "0"*(4-len(s))+s
            a = l[l[i+1]] if ins[1]=="0" else l[i+1]
            b = l[l[i+2]] if ins[0]=="0" else l[i+2]
            if s[-1] in {"2","1"}:
                if s[-1] == "1":
                    l[l[i+3]] = a+b
                else:
                    l[l[i+3]] = a*b
                i += 4
            elif s[-1] in {"5","6"}:
                if s[-1] == "5" and int(a) != 0: i = int(b)
                elif s[-1] == "6" and int(a) == 0: i = int(b)
                else:
                    i += 3
            elif s[-1] in {"7","8"}:
                c = l[i+3]
                if s[-1] == "7":
                    if a < b: l[c] = 1
                    else: l[c] = 0
                else:
                    if a == b:l[c] = 1
                    else: l[c] = 0
                i += 4

q(l)