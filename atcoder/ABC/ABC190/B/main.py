n, s, d = map(int, input().split())
ok = False
for _ in range(n):
    x, y = map(int, input().split())
    if x < s and y > d:
        ok = True
print('Yes' if ok else 'No')