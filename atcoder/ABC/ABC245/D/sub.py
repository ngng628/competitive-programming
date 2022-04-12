import numpy as np
n, m = map(int, input().split())
a = np.poly1d(list(reversed(list(map(int, input().split())))))
c = np.poly1d(list(reversed(list(map(int, input().split())))))
b = (c / a)[0]
print(*reversed([int(k) for k in b]))