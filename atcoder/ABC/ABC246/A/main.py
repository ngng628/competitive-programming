x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

if x1 == x3:
   x2, x3 = x3, x2
   y2, y3 = y3, y2

if x1 == x2:
   y4, x4 = 0, 0
   if y1 == y3:
      y4 = y2
   else:
      y4 = y1
   x4 = x3
   print('{} {}'.format(x4, y4))
else:
   x4 = x1
   y4 = y3 if y1 == y2 else y2
   print('{} {}'.format(x4, y4))