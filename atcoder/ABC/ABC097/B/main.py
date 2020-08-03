x = int(input())

if x == 1:
    print("1")
    exit(0)

ans = 1
for b in range(2, 1000 + 1):
    for p in range(2, 10+1):
        bp = b**p
        if bp <= x:
            ans = max(ans, bp)

print(ans)

