N = int(input())-1
l = len(str(N))

ans = ''

if N == 0:
    print('a')
    exit(0)

cnt = 0
while N >= 26:
    d = N % 26
    ans = chr(ord('a') + d) + ans
    N //= 26
    N -= 1
ans = chr(ord('a') + N) + ans

print(ans)
