with open("q1.txt", "r") as f:
    inp=[int(line) for line in f]

def q1():
    for n in inp:
        if 2020-n in inp:
            print(n*(2020-n))
            break

def q2():
    for i in range(len(inp)):
        for j in range(len(inp)):
            if i!=j:
                if 2020-inp[i]-inp[j] in inp:
                    print((2020-inp[i]-inp[j])*inp[j]*inp[i])
                    return

q2()
