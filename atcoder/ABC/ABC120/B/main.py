import sys
A, B, K = map(int, input().split())

mini = min(A, B)
divisors = []
for i in range(1, mini + 1):
    if A % i == 0 and B % i == 0:
        divisors.append(i)

divisors = divisors[::-1]
print(divisors[K - 1])
