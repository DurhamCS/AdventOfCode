tree_map=[]
with open("3.txt","r") as f:
    for line in f:
        t=line.replace("\n","")
        tree_map.append(list(t))
h=len(tree_map)
w=len(tree_map[0])
def q1():
    y,x=0,0
    c=0
    while y<h-1:
        y+=1
        x=(x+3)%w
        if tree_map[y][x]=="#":
            c+=1
        print(x,y)
    print(c)

def q2():
    ans=1
    for (ox,oy) in ((1,1),(3,1),(5,1),(7,1),(1,2)):
        y,x=0,0
        c=0
        while y<h-1:
            y+=oy
            x=(x+ox)%w
            if tree_map[y][x]=="#":
                c+=1
        ans=ans*c
    print(ans)

q2()
