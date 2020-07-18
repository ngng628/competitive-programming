import random

N = random.randint(1, 10**5)
M = random.randint(1, 10**5)
print(N, M)


for _ in range(M):
    p = random.randint(1, N)
    s = random.randint(1, 2)
    if s == 1:
        S = "AC"
    else:
        S = "WA"
    print(p, S)
