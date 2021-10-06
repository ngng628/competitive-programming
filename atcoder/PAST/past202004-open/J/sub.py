from fractions import Fraction

n, c = map(int, input().split())
pos = [list(map(int, input().split())) for _ in range(n)]
x = [0] * n
y = [0] * n
for i in range(n):
   x[i] = pos[i][0]
   y[i] = pos[i][1]

p = Fraction(sum(x), n)
cost = Fraction(0)
for i in range(n):
   cost += (p - x[i])**2 + (c - y[i])**2
print("{:.10}".format(float(cost)))