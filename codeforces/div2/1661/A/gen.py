import random
t = 4000
print(t)
for _ in range(t):
   n = 25
   print(n)
   print(*[random.randint(0, 10**9) for _ in range(n)])
   print(*[random.randint(0, 10**9) for _ in range(n)])