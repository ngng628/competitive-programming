import sys
input = sys.stdin.readline
import numpy as np

_A = [np.matrix([[0, 1, 0], [-1, 0, 0], [0, 0, 1]]), np.matrix([[0, -1, 0], [1, 0, 0], [0, 0, 1]])]
def A(op):
  return _A[op-1]

def B(op, p):
  if op == 3:
    return np.matrix([[-1, 0, 2*p], [0, 1, 0], [0, 0, 1]])
  else:
    return np.matrix([[1, 0, 0], [0, -1, 2*p], [0, 0, 1]])

n = int(input())
pieces = []
for _ in range(n):
  x, y = map(int, input().split())
  pieces.append(np.matrix([[x],[y],[1]]))

m = int(input())
cumprod = [np.matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])]
for i in range(1, m+1):
  op = list(map(int, input().split()))
  cumprod.append((A(op[0]) if len(op) == 1 else B(op[0], op[1]))*cumprod[i-1])

q = int(input())
for _ in range(q):
  a, b = map(int, input().split())
  x, y, _ = cumprod[a]*pieces[b-1]
  print(x[0,0], y[0,0])
