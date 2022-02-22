from copy import deepcopy

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = deepcopy(a)

for i in range(n):
   d = max(0, b[i] - a[i])
   a[i] = max(0, a[i] - b[i])
   a[i + 1] = max(0, a[i + 1] - d)

print(sum(c[i] - a[i] for i in range(n + 1)))
