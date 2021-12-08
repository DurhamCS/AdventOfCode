r = [130254,678275]

print(sum([str(n) == "".join(sorted(str(n))) and any([str(n)[i-1]==str(n)[i] for i in range(1,len(str(n)))]) for n in range(r[0],r[1]+1)]))

c = 0
for n in range(r[0],r[1]+1):
    s = str(n)
    if s == "".join(sorted(s)):
        i,j = 1,1
        b = False
        while i<len(s) and not b:
            if s[i] == s[i-1]:
                j += 1
            else:
                if j == 2: b = True
                j = 1
            i += 1
        if j == 2: b = True
        if b: c += 1
            
print(c)