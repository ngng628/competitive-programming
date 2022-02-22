a, b = map(int, input().split())
ans = 0
ans += max(a, b)
a, b = max(a, b) - 1, min(a, b)
ans += max(a, b)
print(ans)