import sys
from math import ceil, log
input = sys.stdin.readline

def getDay(p,q):
   d = 1
   while q*d*d*d*d*d < p:
      d += 1
   return d

def isOK(y, p, q, x):
   left = y - x*p + q * x*x*(x + 1)*(x + 1)*(2*x*x + 2*x - 1) // 12
   right = 10**99
   return left >= right

p, q = map(int, input().split())

day = getDay(p,q)

y = 0
for i in range(day - 1, -1, -1):
   y += p
   y -= i*i * i*i * i

mx = 10**100
mn = 0
mid = (mx + mn) // 2

while mx - mn > 1:
   if isOK(y, p, q, mid):
      mx = mid
   else:
      mn = mid
   mid = (mx + mn) // 2

print(y)
print(mx)