L = list(map(int, input().split()))
L.sort()
b = L.count(L[2])

if b == 2:
    print(L[0])
else:
    print(L[2])
