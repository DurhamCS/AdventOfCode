inp=[]
with open("one.txt", "r") as f:
    t=[]
    for n in f:
        if n=="\n":
            inp.append(t)
            t=[]
        else:
            t.append(n)
            
inp=[sum([[j.replace("\n","") for j in i.split()] for i in n],[]) for n in inp]
inpd={}
for n in inp:
    i=inp.index(n)
    inpd[i]=[]
    t={}
    for x in n:
        (k,v)=x.split(":")
        t[k]=v
    inpd[i]=t

def q1():
    c=0
    check=["byr","iyr","eyr","hgt","hcl","ecl","pid"]
    for n in inpd:
        t=True
        for x in check:
            if x in inpd[n].keys():
                pass
            else:
                t=False
                break
        if t:
            c+=1
        else:
            pass
            #print(sorted(inpd[n].keys()))
    print(c)

def q2():
    c=0
    hair=[str(n) for n in range(10)]+["a","b","c","d","e","f"]
    eye="amb blu brn gry grn hzl oth".split(" ")
    for n in inpd:
        t=True
        k=inpd[n].keys()
        d=inpd[n]

        #birth yr
        if "byr" in k and t:
            if not 1920<=int(d["byr"])<=2002:
                t=False
        else:
            t=False
        #issue year
        if "iyr" in k and t:
            if not 2010<=int(d["iyr"])<=2020:
                t=False
        else:
            t=False
        #expire year
        if "eyr" in k and t:
            if not 2020<=int(d["eyr"])<=2030:
                t=False
        else:
            t=False
        #height in cm or in
        if "hgt" in k and t:
            try:
                if "cm" in d["hgt"]:
                    if not 150<=int(d["hgt"].replace("cm",""))<=193:
                        t=False
                elif "in" in d["hgt"]:
                    if not 59<=int(d["hgt"].replace("in",""))<=76:
                        t=False
                else:
                    t=False
            except:
                t=False
        else:
            t=False
        #hair colour 6 digit hex after #
        if "hcl" in k and t:
            if d["hcl"][0]=="#" and len(d["hcl"])==7:
                for n in d["hcl"][1:]:
                    if n not in hair:
                        t=False
                        break
            else:
                t=False
        else:
            t=False
        #eye colour in given list[str]
        if "ecl" in k and t:
            if d["ecl"] not in eye:
                t=False
        else:
            t=False
        #passport id of digit len 9
        if "pid" in k and t:
            if len(d["pid"])==9:
                try:
                    test=int(d["pid"])
                except:
                    t=False
            else:
                t=False
        else:
            t=False

        if t:
            c+=1
    print(c)

q2()
