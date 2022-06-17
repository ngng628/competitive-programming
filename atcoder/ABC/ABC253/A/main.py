a, b, c = map(int, input().split())
s = a + b + c
if s - max(a, b, c) - min(a, b, c) == b:
   print('Yes')
else:
   print('No')