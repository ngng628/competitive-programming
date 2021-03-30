n = int(input())
st = set()
for a in range(2, n+1):
   b = 2
   if a**b > n:
      break
   while True:
      p = a**b
      if p > n:
         break
      st.add(p)
      b += 1
print(n - len(st))