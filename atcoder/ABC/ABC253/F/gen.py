from random import randint
n = randint(2, 5)
m = randint(2, 5)
q = randint(1, 5)
print(n, m, q)
for c in range(q):
   t = randint(1, 3)
   if c == q - 1:
      t = 3
   if t == 1:
      l = randint(1, m)
      r = randint(l, m)
      x = randint(1, 10)
      print(t, l, r, x)
   elif t == 2:
      i = randint(1, n)
      x = randint(1, 10)
      print(t, i, x)
   else:
      i = randint(1, n)
      j = randint(1, m)
      print(t, i, j)