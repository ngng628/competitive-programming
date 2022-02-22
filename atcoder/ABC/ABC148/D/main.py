n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))

ans = 0
now = 0
for i in range(n):
   if a[i] == now:
      now += 1
   else:
      ans += 1

print(-1 if ans == n else ans)
