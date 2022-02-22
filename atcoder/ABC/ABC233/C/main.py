n, x = map(int, input().split())
a = [list(map(int, input().split()))[1:] for _ in range(n)]

ans = 0
def rec(i, prod):
   global ans

   if i == n:
      if prod == x:
         ans += 1
      return

   for e in a[i]:
      rec(i + 1, prod * e)

rec(0, 1)

print(ans)
