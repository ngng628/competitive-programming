def divisor(n):
    res = list()
    i = 1
    while i*i <= n:
        if n % i == 0:
            res.append(i)
            if i*i != n:
                res.append(n // i)
        i += 1
    res.sort()
    return res

n = int(input())
for ans in divisor(n):
    print(ans)
