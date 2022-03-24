n = int(input())
s = input()

dydx = [[1, 0], [0, -1], [-1, 0], [0, 1]]
cur = 0

x, y = 0, 0
for c in s:
   if c == 'S':
      x += dydx[cur][0]
      y += dydx[cur][1]
   else:
      cur = (cur + 1) % 4

print(x, y)
