from math import gcd
import sys
input = sys.stdin.readline

n = int(input())
xy = [map(int, input().split()) for _ in range(n)]
x, y = [list(p) for p in zip(*xy)]

st = set()
for i in range(n):
   for j in range(n):
      if i == j:
         continue
      Δx = x[j] - x[i]
      Δy = y[j] - y[i]
      g = gcd(Δx, Δy)
      st.add((Δx // g, Δy // g))

print(len(st))