n = int(input())
a, b, c = map(int, input().split())

ans = 10**18
for i in range(10000):
   for j in range(10000):
      t = n - a*i - b*j
      if t < 0: continue
      if t % c == 0:
         ans = min(ans, i + j + t // c)
print(ans)