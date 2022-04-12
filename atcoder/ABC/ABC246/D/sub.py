def P(a: int, b: int):
   return a**3 + a**2*b + a*b**2 + b**3

n = int(input())

ans = 10**18
for a in range(1000001):
   if P(a, 0) >= n:
      if ans > P(a, 0):
         ans = P(a, 0)
   ac = 1000000
   wa = 0

   while ac - wa > 1:
      wj = (ac + wa) // 2
      if P(a, wj) >= n:
         ac = wj
      else:
         wa = wj
   
   if ans > P(a, ac):
      ans = P(a, ac)

print(ans)