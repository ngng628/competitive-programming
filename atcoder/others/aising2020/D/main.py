def popcount(x):
    cnt = 0
    while x != 0:
        cnt += 0 if x % 2 == 0 else 1
        x //= 2
    return cnt

def f(b):
    cnt = 0
    while b != 0:
        n = popcount(b)
        b = b % n
        cnt += 1

    return cnt

N = int(input())
X = input()

B = int(X, 2)

li = []
li.append(1)
for i in range(1, N+1):
    li.append(2*li[i-1])

for i in range(0, N):
    tmp = X
    b = B
    b = b ^ li[N-i]
    print(f(b))
