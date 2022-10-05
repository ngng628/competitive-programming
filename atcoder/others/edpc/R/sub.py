import numpy as np

def det(a):
   return np.linalg.det(a)

def inv(a):
   return a.I

# a = np.matrix([[1, 2, 3], [4, 5, 6]], dtype=int)
# b = np.matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]], dtype=int)
# print(b)
# print(det(b))

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
print(int(det(np.matrix(a, dtype=int))))