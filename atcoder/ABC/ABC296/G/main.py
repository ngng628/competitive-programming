# cross product: (b - a)×(c - a)
def cross3(a, b, c):
    return (b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0])


# O(log N)
def inside_convex_polygon(p0, qs):
    L = len(qs)
    left = 1; right = L
    q0 = qs[0]
    while left+1 < right:
        mid = (left + right) >> 1
        if cross3(q0, p0, qs[mid]) <= 0:
            left = mid
        else:
            right = mid
    if left == L-1:
        left -= 1

    qi = qs[left]; qj = qs[left+1]
    v0 = cross3(q0, qi, qj)
    v1 = cross3(q0, p0, qj)
    v2 = cross3(q0, qi, p0)
    if v0 < 0:
        v1 = -v1; v2 = -v2
    
    if v1 == 0 or v2 == 0:
        return 2
    elif 0 <= v1 and 0 <= v2 and v1 + v2 <= v0:
        return 0
    else:
        return 1

n = int(input())

def read():
    x, y = map(int, input().split())
    return (x, y)

qs = [read() for _ in range(n)]

q = int(input())
d = {0: 'IN', 1: 'OUT', 2: 'ON'}
ans = map(lambda x: d[x], [inside_convex_polygon(read(), qs) for _ in range(q)])
print('\n'.join(ans))
