import random
N = 5000
print(N, 10**9)
li = list(range(1, N + 1, 1))
li.sort()
for i in range(N):
    print(li[i], end=" ")
print("")

s = -10**9
e = 10**9
for i in range(N):
    print(random.randint(s, e), end=" ")
print("")


