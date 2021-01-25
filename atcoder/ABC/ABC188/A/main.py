x, y = map(int, input().split())
mx = max(x, y)
mn = min(x, y)
print('Yes' if mn + 3 > mx else 'No')