import math
N = int(input())
xs = list(map(int, input().split()))
A = sum(xs) / N
for x in xs:
    print(math.floor(50 - (A - x) / 2))
