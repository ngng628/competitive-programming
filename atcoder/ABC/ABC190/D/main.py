n_loop = 10**7
N = int(input())
ans = 0
for n in range(1, n_loop):
    if (2*N) % n == 0 and ((2*N) // n - n + 1) % 2 == 0:
        a = ((2*N) // n - n + 1) // 2
        if a > 0:
            ans +=  1
print(2*ans)