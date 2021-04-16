from math import sqrt
R, X, Y = map(int, input().split())

d = int(sqrt(X*X + Y*Y))
if d == R:
   print(1)
elif d <= 2*R:
   print(2)
else:
   ng = 0
   ok = 10**100

   while abs(ok - ng) > 1:
      mid = (ok + ng) // 2

      if (mid*R)**2 >= X**2 + Y**2: ok = mid
      else: ng = mid

   print(ok)