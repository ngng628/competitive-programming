MOD = 998244353
n, k, m = map(int, input().split())
if m % MOD == 0:
   print(0)
else:
   r = pow(k, n, MOD - 1)
   print(pow(m, r, MOD))
