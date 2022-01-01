import os
l = [l.strip() for l in open(os.path.dirname(__file__)+"/inp.txt").readlines()][0]
l = [[int(m) for m in n[2:].split("..")] for n in l[13:].split(", ")]

def hori(steps,u):
    c = 0
    while steps > 0:
        c += u
        steps -= 1
        u += -1 if u>0 else 1 if u<0 else 0
    return l[0][0] <= c <= l[0][1]

def verti(uy,y0,y1):
    steps = []
    step = 0
    c = 0
    while c >= y0:
        step += 1
        c += uy
        uy -= 1
        if y0<=c<=y1: steps.append(step)
    return steps

def q1(l):
    max_h = None
    uy = sorted([n for n in range(l[1][0]+1,l[1][1]+1)] + [n for n in range((l[1][0])//2+1,0)]) + [0]
    for u in uy:
        step = 2*abs(u)+2 if l[1][0]<=u<=l[1][1] else 2*abs(u)+3
        for ux in range(100, -1, -1):
            if hori(step,ux):
                print(sum([n for n in range(abs(u)+1)]))
                break
        if max_h is None: break

def q2(l):
    [[x0,x1],[y0,y1]] = l
    v = 0
    for uy in range(-1000,1000):
        y = uy
        steps = verti(uy,y0,y1)
        for ux in range(1000):
            if any([hori(n,ux) for n in steps]):
                v += 1
    print(v)

def vis(l): 
    import matplotlib.pyplot as plt
    import matplotlib.patches as mpatches

    diff = [[7, 2], [6, 3], [9, 0], [17, -4], [7, 7], [7, 8], [7, 6], [6, 5], [7, 5], [7, 9], [6, 6], [6, 9]]
    [[x0,x1],[y0,y1]] = l
    rect = [[x0,x0,x1,x1,x0],[y0,y1,y1,y0,y0]]
    fig,axis = plt.subplots(3,4)
    for i in range(3):
        for j in range(4):
            ux,uy = diff[i*4+j]
            X = [0]
            Y = [0]
            cur = [0,0]
            axis[i,j].set_title(f"x vel = {ux}, y vel = {uy}")
            #axis[i,j].set_xlim(-5,35)
            #axis[i,j].set_ylim(-20,50)
            while True:
                cur[0] += ux
                if ux > 0: ux -= 1
                elif ux < 0: ux += 1
                cur[1] += uy
                uy -= 1
                X.append(cur[0])
                Y.append(cur[1])
                if cur[1] < y0: break
            axis[i,j].plot(X,Y)
            axis[i,j].scatter(X,Y,color="green",s=8)
            axis[i,j].plot(rect[0],rect[1])
    plt.tight_layout()
    plt.show()

q1(l)
q2(l)
#vis(l)