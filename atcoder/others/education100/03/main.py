def ACGT(s):
    A = s.count('A')
    C = s.count('C')
    G = s.count('G')
    T = s.count('T')
    return len(s) == A+C+G+T

S = input()

ans = 0
for i in range(len(S)+1):
    for k in range(i+1, len(S)+1):
        sub = S[i:k]
        if ACGT(sub):
            if ans < len(sub):
                ans = len(sub)

print(ans)
