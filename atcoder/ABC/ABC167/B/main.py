a, b, _c, K = map(int, input().split())

if K <= a:
   print(K)
elif K <= a + b:
   print(a)
else:
   print(2*a + b - K)
