import os
with open (os.path.dirname(__file__)+"/inp.txt") as f:
    l = [n.strip() for n in f.readlines()]
    l = [[m.strip() for m in n.split("|")] for n in l]
    l = [[a.split(" "),b.split(" ")] for a,b in l]
    l = [[["".join(sorted(k)) for k in m] for m in n] for n in l]

t_d = {
    "abcefg":0,
    "cf":1,
    "acdeg":2,
    "acdfg":3,
    "bcdf":4,
    "abdfg":5,
    "abdefg":6,
    "acf":7,
    "abcdefg":8,
    "abcdfg":9
}

ans = 0
ez = {2:1,4:4,3:7,7:8}
a_map = {"a":0,"b":1,"c":2,"d":3,"e":4,"f":5,"g":6}
inv_a_map = {v: k for k, v in a_map.items()}
for a,b in l:
    enc_arr = [None]*7
    d = {(0,6,9):set(),(2,3,5):set()}
    d1 = {}
    for n in a:
        if len(n) in ez:
            if ez[len(n)] not in d1:
                d1[ez[len(n)]] = set(n)
        else:
            for k in d:
                if len(n) in k:
                    d[k].add(n)
                    break
    for k in d:
        tr = set.intersection(*map(set,[n for n in d[k]]))
        d[k] = [tr,[set(n)^tr for n in d[k]]]
    #intersect of 7 and 1 -> a
    (enc_arr[a_map["a"]],) = d1[1]^d1[7]
    #ce cf bf = 2,3,5 -> eb. eb ^ d[4] -> b
    (enc_arr[a_map["b"]],) = (d[(2,3,5)][1][0]^d[(2,3,5)][1][1]^d[(2,3,5)][1][2])&d1[4]
    #1 & any of (0,6,9) -> c
    enc_arr[a_map["c"]] = [list(n&d1[1])[0] for n in d[(0,6,9)][1] if len(n&d1[1])>0][0]
    #4 ^ (b,c) & 1 -> f
    (enc_arr[a_map["f"]],) = (d1[4]^set([enc_arr[a_map["b"]],enc_arr[a_map["c"]]]))&d1[1]
    #following above, find remaining segment on 4 -> d
    (enc_arr[a_map["d"]],) = d1[4]^set([enc_arr[a_map["b"]],enc_arr[a_map["c"]],enc_arr[a_map["f"]]])
    #using 0,6,9 -> e
    t = [n for n in d[(0,6,9)][1] if len(n^set([enc_arr[a_map["c"]],enc_arr[a_map["d"]]]))>0]
    (enc_arr[a_map["e"]],) = t[0]&t[1]
    #reminaing letter -> g
    (enc_arr[a_map["g"]],) = set([n for n in enc_arr if n is not None]) ^ d1[8]
    b = ["".join(sorted([inv_a_map[enc_arr.index(m)] for m in n])) for n in b]
    ans += int("".join([str(t_d[n]) for n in b]))
print(ans)