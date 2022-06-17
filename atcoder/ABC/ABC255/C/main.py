X, A, D, N = map(int, input().split())

if D == 0:
   print(abs(A - X))
elif D > 0:
   ok = 10**20
   ng = -10**20
   while ok - ng > 1:
      mid = (ok + ng) >> 1
      if D*mid + A - D >= X:
         ok = mid
      else:
         ng = mid

   ans = 10**20
   for i in range(-10, 11):
      tmp = D * min(max(ok + i, 1), N) + A - D
      d = abs(tmp - X)
      if d < ans:
         ans = d

   print(ans)
else:
   ok = 10**20
   ng = -10**20
   while ok - ng > 1:
      mid = (ok + ng) >> 1
      if D*mid + A - D <= X:
         ok = mid
      else:
         ng = mid

   ans = 10**20
   for i in range(-10, 11):
      tmp = D * min(max(ok + i, 1), N) + A - D
      d = abs(tmp - X)
      if d < ans:
         ans = d

   print(ans)
