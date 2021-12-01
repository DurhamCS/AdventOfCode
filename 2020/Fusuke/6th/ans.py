with open("inp.txt", "r") as f:
    inp=[]
    t=[]
    for n in f:
        if n=="\n":
            inp.append(t)
            t=[]
        else:
            t.append(n.replace("\n",""))
    inp.append(["lfhtzrxcj","fbtzlhrcj","lzdaftrjphco"])

print(inp)
    
def q1():
    s=0
    for grp in inp:
        p=set()
        for x in grp:
            for l in x:
                p.add(l)
        s+=len(p)
    print(s)

def q2():
    from collections import Counter
    s=0
    for grp in inp:
        grp_ans="".join([n for n in grp])
        grp_size=len(grp)
        c=Counter(grp_ans)
        for key,val in c.items():
            if val>=grp_size:
                s+=1
    print(s)

q2()
