x, y = map(int, input().split('.'))
if y <= 2:
   print(f'{x}-')
elif y <= 6:
   print(f'{x}')
else:
   print(f'{x}+')