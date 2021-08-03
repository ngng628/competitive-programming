a, b, c = map(int, input().split())
if c % 2 == 0: c = 2
else: c = 1

if a**c < b**c:
   print('<')
elif a**c == b**c:
   print('=')
else:
   print('>')