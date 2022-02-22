x = input()
n = len(x)
ans = 10**20
for d in range(-9, 10):
   for d0 in range(0, 10):
      ok = True
      s = ''
      for i in range(n):
         now = d0 + d*i
         if not (0 <= now <= 9):
            ok = False
            break
         s += f'{now}'
      if int(s) >= int(x):
         ans = min(ans, int(s))
print(ans)