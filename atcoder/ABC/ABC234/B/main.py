n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]

ans = 0
for x1, y1 in xy:
   for x2, y2 in xy:
      dist = (x2 - x1)**2 + (y2 - y1)**2
      ans = max(ans, dist)

from math import sqrt
print(f'{sqrt(ans):.7f}')