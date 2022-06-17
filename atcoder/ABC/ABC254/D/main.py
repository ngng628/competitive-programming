from math import sqrt
n = int(input())

squares = [i * i for i in range(n + 10)]

def is_square(n):
   return int(sqrt(i))**2 == i

ans = 0
for i in range(1, n + 1):
   # i * sq[j] >= N を満たす j
   ng = len(squares)
   ok = -1

   # スタート = 素因数分解して、

   while abs(ok - ng) > 1:
      mid = (ok + ng) // 2
      
      lhs = idx * squares[mid]
      if lhs <= n:
         ok = mid
      else:
         ng = mid
   print(f'({i}) ok = {ok}, sq[ok] = {squares[ok]}')
   ans += ok

print(ans)