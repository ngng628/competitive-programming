import math

a, b, x = map(int, input().split())

if a == b:
    if a % x == 0:
        print(1)
    else:
        print(0)

elif a % x == 0:
    print(math.ceil((b - a) // x) + 1)
else:
    print(math.ceil((b - a) // x))

