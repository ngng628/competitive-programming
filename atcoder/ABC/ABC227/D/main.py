import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))

ok = 0
ng = 2*10**17 + 1
while abs(ok - ng) > 1:
   mid = (ok + ng) // 2
   s = sum(min(A[i], mid) for i in range(N))
   if mid * K > s:
      ng = mid
   else:
      ok = mid

print(ok)