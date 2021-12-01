with open("inp.txt", "r") as f:
    inp=[]
    for n in f:
        inp.append(n[:-1])

def decode_seat_num(inp):
    r=inp[:7]
    c=inp[7:]
    r_num=[0,127]
    c_num=[0,7]

    for n in r:
        diff=r_num[1]-r_num[0]
        if n=="F":
            r_num[1]-=(diff+1)//2
        elif n=="B":
            r_num[0]+=(diff+1)//2
    for n in c:
        diff=c_num[1]-c_num[0]
        if n=="R":
            c_num[0]+=(diff+1)//2
        elif n=="L":
            c_num[1]-=(diff+1)//2
    return (r_num[0],c_num[0],r_num[0]*8+c_num[0])

def q1():
    ans_id=0
    for n in inp:
        ans_id=max(ans_id,decode_seat_num(n)[2])
    print(ans_id)

def q2():
    id_list=[decode_seat_num(n)[2] for n in inp]
    full_list=[n for n in range(min(id_list),max(id_list))]
    print(sorted(id_list))
    for n in full_list:
        if n not in id_list:
            if n-1 in id_list and n+1 in id_list:
                print(n)
    
q2()
