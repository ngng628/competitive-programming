def P(a: int, b: int):
   return a**3 + a**2*b + a*b**2 + b**3

n = int(input())
b = 10**6
ans = 2*10**18
for a in range(10**6 + 1):
   while P(a, b) >= n:
      if b < 0:
         break
      b -= 1
   if ans > P(a, b + 1):
      ans = P(a, b + 1)

print(ans)