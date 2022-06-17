import math
n, a, b = map(int, input().split())

def lcm(a, b):
   y = a*b // math.gcd(a, b)
   return y

def Sum(n, a):
   lim = n // a
   res = lim * (2*a + (lim - 1) * a) // 2
   return res

s = Sum(n, 1)
sa = Sum(n, a)
sb = Sum(n, b)
sab = Sum(n, lcm(a, b))

print(s - sa - sb + sab)