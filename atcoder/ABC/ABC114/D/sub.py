N = int(input())
e = [0] * (N+1)
for i in range(2, N+1):
   cur = i
   for j in range(2, i+1):
      while cur % j == 0:
         e[j] += 1
         cur //= j
print(e)