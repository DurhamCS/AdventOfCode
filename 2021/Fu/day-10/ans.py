import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    l = [n.strip() for n in f.readlines()]

    closer = {")":"(","]":"[","}":"{",">":"<"}

def q1(l):
    score_d = {")":3,"]":57,"}":1197,">":25137}
    tot = 0
    for s in l:
        v = 0
        while len(s)>0:
            c = False
            for n in ("()","[]","{}","<>"):
                if n in s:
                    c = True
                    s = s.replace(n,"")
            if not c: break
        for i in range(len(s)):
            if s[i] in closer and closer[s[i]] != s[i-1]:
                v = score_d[s[i]]
                break
        tot += v
    print(tot)

def q2(l):
    score_d = {"(":1,"[":2,"{":3,"<":4}
    scores = []
    for s in l:
        while len(s)>0:
            c = False
            for n in ("()","[]","{}","<>"):
                if n in s:
                    c = True
                    s = s.replace(n,"")
            if not c: break
        c = False
        for i in range(len(s)):
            if s[i] in closer and closer[s[i]] != s[i-1]:
                c = True
                break
        if not c:
            v = 0
            for n in reversed(s):
                v *= 5
                v += score_d[n]
            scores.append(v)
    scores.sort()
    print(scores[len(scores)//2])
    
q1(l)
q2(l)