def f(n):
    if n < 2:
        return 1
    else:
        return n*f(n-2)

for i in range(1101):
    s = str(f(i))
    cnt = 0
    for k in range(len(s)):
        if s[len(s) - k - 1] == '0':
            cnt += 1
        else:
            break
    print('f({}) := {}'.format(i, cnt))
