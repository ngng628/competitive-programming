a, b, c, x = map(int, input().split())
if x <= a:
   print(1.0)
elif a + 1 <= x <= b:
   print(f'{c / abs(b - a):.10}')
else:
   print(f'{0.0:.10}')
