n = int(input())
s = [input() for _ in range(n)]

st = dict()
for e in s:
   st[e] = 0

for e in s:
   st[e] += 1

mx = 0
for value in st.values():
   mx = max(mx, value)

for key, value in st.items():
   if mx == value:
      print(key)