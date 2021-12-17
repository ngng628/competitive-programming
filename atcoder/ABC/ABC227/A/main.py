import sys
input = sys.stdin.readline
n, k, a =map(int, input().split())

f = a
for _ in range(k - 1):
   f += 1
   if f == n + 1:
      f = 1

print(f)