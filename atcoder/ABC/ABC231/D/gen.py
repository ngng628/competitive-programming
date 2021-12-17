import random as rnd
n = rnd.randint(2, 6)
m = rnd.randint(0, 6)

print(n, m)
st = set()
i = 0
while i < m:
   a = rnd.randint(1, n)
   b = rnd.randint(1, n)
   if a > b:
      a, b = b, a
   if a == b:
      continue
   if (a, b) in st:
      continue
   st.add((a, b))
   print(a, b)
   i += 1
