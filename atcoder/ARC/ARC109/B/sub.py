import math
from math import log2

def f(n):
  return n*(n+1) // 2

def isOK(index, key):
  return f(index) <= key

def binary_chop(key):
  ok = 0
  ng = key

  while abs(ok - ng) > 1:
    mid = (ok + ng) // 2
    if isOK(mid, key):
      ok = mid
    else:
      ng = mid

  return ok

n = int(input())
s = bs(n + 1)
print(1 + n - s)
