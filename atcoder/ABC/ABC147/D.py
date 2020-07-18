N = int(input())
A = list(map(int, input().split()))

s = 0
for i in range(0, N - 1):
    for j in range(i, N):
        s += (A[i] ^ A[j])
        s %= (10**9 + 7)

print(s % (10**9 + 7))

