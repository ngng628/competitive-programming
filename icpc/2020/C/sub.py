def divisor(n):
    low, up = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            low.append(i)
            if i != n // i:
                up.append(n // i)
        i += 1
    return low + up[::-1]

def Main(p):
    lst = divisor(p)
    n = len(lst)
    ans = 10**16
    for i in range(n):
        for k in range(n):
            a = lst[i]
            b = lst[k]
            ab = a*b
            if p % ab == 0:
                ans = min(ans, a + b + (p // ab))
    print(ans)

while True:
    p = int(input())
    if p == 0: break
    Main(p)
