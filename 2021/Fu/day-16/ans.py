import os
l = [l.strip() for l in open(os.path.dirname(__file__)+"/inp.txt").readlines()][0]

def literal(l,si):
    i = si
    s = ""
    while i < len(l):
        s += l[i + 1:i + 5]
        if l[i] == "0": break
        i += 5
    return s

def parse(l):
    #print(l)
    ver = int(l[:3],2)
    id = int(l[3:6],2)
    if id == 4: #lit val
        val = literal(l,6)
        total_l = 6 + len(val)//4 + len(val)
        #print(f"lit with ver = {ver}, val = {val}, total_l = {total_l}")
        return ver,val,total_l
    else:
        l_id = int(l[6])
        i = 7
        s_ver = 0
        if l_id == 0:
            og_tot_l = int(l[i:i+15],2)
            tot_l = og_tot_l
            #print(f"operation 0, tot_l = {tot_l}")
            i += 15
            while tot_l > 6:
                t = parse(l[i:i+tot_l])
                s_ver += t[0]
                tot_l -= t[2]
                i += t[2]
                #print(f"sub = {t}, cur tot_l = {tot_l}")
            return s_ver + ver,"0"*(i), i
        else:
            num_sub = int(l[i:i+11],2)
            i += 11
            #print(f"operation 1, num_sub = {num_sub}")
            for subs in range(num_sub):
                t = parse(l[i:])
                s_ver += t[0]
                i += t[2]
                #print(f"sub {subs} = {t}")
            return s_ver + ver,"0"*(i), i

L = [
    "8A004A801A8002F478",
    "620080001611562C8802118E34",
    "C0015000016115A2E0802F182340",
    "A0016C880162017C3686B18A3D4780"
]

#print(l)
l = format(int(l,16),f"0>{len(l)*4}b")
#q1
print(parse(l)[0])

#q2
from math import prod
def parse(l):
    #print(l)
    ver = int(l[:3],2)
    id = int(l[3:6],2)
    if id == 4: #lit val
        val = literal(l,6)
        total_l = 6 + len(val)//4 + len(val)
        #print(f"lit with ver = {ver}, val = {val}, total_l = {total_l}")
        return ver,int(val,2),total_l
    else:
        l_id = int(l[6])
        i = 7
        s_ver = 0
        sub_vals = []
        if l_id == 0:
            og_tot_l = int(l[i:i+15],2)
            tot_l = og_tot_l
            #print(f"operation 0, tot_l = {tot_l}")
            i += 15
            while tot_l > 6:
                t = parse(l[i:i+tot_l])
                s_ver += t[0]
                tot_l -= t[2]
                i += t[2]
                sub_vals.append(t[1])
                #print(f"sub = {t}, cur tot_l = {tot_l}")
        else:
            num_sub = int(l[i:i+11],2)
            i += 11
            #print(f"operation 1, num_sub = {num_sub}")
            for subs in range(num_sub):
                t = parse(l[i:])
                s_ver += t[0]
                i += t[2]
                sub_vals.append(t[1])
                #print(f"sub {subs} = {t}")
        if id == 0: #sum
            return s_ver + ver, sum(sub_vals), i
        elif id == 1: #product
            return s_ver + ver, prod(sub_vals), i
        elif id == 2: #min
            return s_ver + ver, min(sub_vals), i
        elif id == 3: #max
            return s_ver + ver, max(sub_vals), i
        elif id == 5: #>
            return s_ver + ver, 1 if sub_vals[0] > sub_vals[1] else 0, i
        elif id == 6: #<
            return s_ver + ver, 1 if sub_vals[0] < sub_vals[1] else 0, i
        elif id == 7: #=
            return s_ver + ver, 1 if sub_vals[0] == sub_vals[1] else 0, i

print(parse(l))