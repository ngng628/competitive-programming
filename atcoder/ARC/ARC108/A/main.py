import math
S, P = map(int, input().split())

D = S**2 - 4*P
Ds = int(math.sqrt(D))
if Ds**2 == D and -S - D < 0 and (-S - D) % 2 == 0:
  print('Yes')
else:
  print('No')
