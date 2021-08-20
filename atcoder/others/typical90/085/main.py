def divisor(n):
   lower, upper = [], []
   i = 1
   while i*i <= n:
      if n % i == 0:
         lower.append(i)
         if i != n // i:
            upper.append(n // i)
      i += 1
   return lower + upper[::-1]

k = int(input())
d = divisor(k)

ans = 0
for i in range(len(d)):
   for j in range(i, len(d)):
      a = d[i]
      b = d[j]
      c = k // (a*b)
      if k % (a*b) == 0 and a <= b <= (k // (a*b)):
         ans += 1

print(ans)