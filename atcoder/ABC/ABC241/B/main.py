n, m = map(int, input().split())
a = list(map(int, input().split()))
used = [False for _ in a]
b = list(map(int, input().split()))

ok = True
for i in range(m):
   t = False
   for j in range(n):
      if b[i] == a[j] and not used[j]:
         t = True
         used[j] = True
         break
   ok = ok & t

print('Yes' if ok else 'No')
