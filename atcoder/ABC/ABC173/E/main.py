import time
s = time.time()
import random as rnd
MOD = 1000000007

N, K = map(int, input().split())
A = list(map(int, input().split()))

A.sort(key=abs)
A.reverse()

ans = A[0]
fact = 0

for i in range(1, K):
    ans = (ans * A[i])

indexes = [x for x in range(K)]

t = 0
while t <= 1.900:
    index1 = rnd.choice(indexes)
    while True:
        index2 = rnd.randint(0, N-1)
        if not (index2 in indexes):
            break


    old = ans
    
    ans //= A[index1]
    ans *= A[index2]

    if old >= ans:
        ans = old
    else:
        indexes.remove(index1)
        indexes.append(index2)
    t = time.time() - s

print(ans % 1000000007)
