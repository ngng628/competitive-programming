import math
n = int(input())
a = math.floor(1.08 * n)
if a < 206:
   print('Yay!')
elif a == 206:
   print('so-so')
else:
   print(':(')