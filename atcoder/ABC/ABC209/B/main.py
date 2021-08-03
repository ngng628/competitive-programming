n, x = map(int, input().split())
a = list(map(int, input().split()))
s = 0
for i in range(n):
   if i % 2 == 1:
      s += a[i] - 1
   else:
      s += a[i]
print('Yes' if x >= s else 'No')