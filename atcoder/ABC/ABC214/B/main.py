s, t = map(int, input().split())

ans = 0
for i in range(120):
   for j in range(120):
      for k in range(120):
         if i + j + k <= s and i*j*k <= t:
            ans += 1
print(ans)