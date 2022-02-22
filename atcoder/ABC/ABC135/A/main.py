a, b = map(int, input().split())
d = abs(a - b)
print(min(a, b) + d // 2 if d % 2 == 0 else 'IMPOSSIBLE')
