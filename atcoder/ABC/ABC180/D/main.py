x, y, a, b = map(int, input().split())
now = x
ex = 0
while True:
    if a*now < b + now:
        if a*now < y:
            now *= a
            ex += 1
        else:
            break
    else:
        break

if (y - now) % b == 0:
    ex += (y - now) // b - 1
else:
    ex += (y - now) // b

print(ex)
