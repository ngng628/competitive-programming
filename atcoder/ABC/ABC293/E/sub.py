def f(a, r, n, mod):
   q = r - 1
   mod2 = mod * q
   p = a * (pow(r, n, mod2) - 1) % mod2
   return p // q

a, x, m = map(int, input().split())
if a == 1:
   print(x % m)
else:
   print(f(1, a, x, m) % )