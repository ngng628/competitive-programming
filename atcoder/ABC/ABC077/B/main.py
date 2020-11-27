from math import sqrt
n = int(input())
for i in range(n, 0, -1):
    if int(sqrt(i))**2 == i:
        print(i)
        exit(0)
