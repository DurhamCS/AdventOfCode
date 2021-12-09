# part 1
print(sum((len(seq) in (2, 3, 4, 7) for line in open('input.txt').readlines() for seq in line.split('|')[1].split())))

# part 2
print(sum((int(''.join(str({v: k for k, v in (lambda W: (lambda S, W: (lambda S, W: {**S, **{9 if len(set(w) & set(S[3])) == 5 else (0 if len(set(w) & set(S[1])) == 2 else 6): ''.join(sorted(w)) for w in W[6:9]}})({**S, **{3 if len(set(w) & set(S[1])) == 2 else (2 if len(set(w) & set(S[4])) == 2 else 5): ''.join(sorted(w)) for w in W[3:6]}}, W))({1: W[0], 7: W[1], 4: W[2], 8: W[9]}, W))([''.join(sorted(w)) for w in list(sorted(l.split('|')[0].split(), key=lambda x: len(x)))]).items()}[''.join(sorted(s))]) for s in l.split('|')[1].split()))) for l in open('input.txt').readlines()))