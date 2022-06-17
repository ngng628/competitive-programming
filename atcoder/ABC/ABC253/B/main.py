h, w = map(int, input().split())
s = [input() for _ in range(h)]

pos = [[-1, -1], [-1, -1]]
cur = 0
for i in range(h):
   for j in range(w):
      if cur < 2 and s[i][j] == 'o':
         pos[cur] = [i, j]
         cur += 1

print(abs(pos[0][0] - pos[1][0]) + abs(pos[0][1] - pos[1][1]))