n, k = map(int, input().split())

ans = 0
for dice in range(1, n + 1):
   i = 0
   while dice * 2**i < k:
      i += 1
   ans += 0.5**i

ans /= n
print(f'{ans:.10f}')
