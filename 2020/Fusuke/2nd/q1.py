inp=[]
with open("inp1.txt", "r") as f:
    for l in f:
        inp.append(l[:-1])
        if inp[-1]=="2-7 b: fdbvbd":
            inp[-1]="2-7 b: fdbvbdb"

def q1():
    count=0
    for n in inp:
        r,letter,password=n.split(" ")[0],n.split(" ")[1][0],n.split(" ")[2]
        rule=(r.split("-"))
        c=0
        for m in password:
            if m==letter:
                c+=1
        if int(rule[0])<=c<=int(rule[1]):
            count+=1
    print(count)

def q2():
    count=0
    for n in inp:
        r,l,p=n.split(" ")
        l=l[0]
        r=[int(n)-1 for n in r.split("-")]
        if r[1]<len(p) :
            if (p[r[0]]==l and p[r[1]]!=l) or (p[r[0]]!=l and p[r[1]]==l):
                count+=1
    print(count)


q1()
q2()
