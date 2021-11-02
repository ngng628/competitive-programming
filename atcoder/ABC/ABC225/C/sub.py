n = 20
m = 7

for i in range(1, n + 1):
   for j in range(1, m + 1):
      print('{:4}'.format((i - 1) * 7 + j), end=' ')
   print()