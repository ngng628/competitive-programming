n = int(input())
dp = [33550336 for _ in range(n+1)]
dp[0] = 0
for i in range(n+1):
    dp[i] = min(dp[i], dp[i-1] + 1)
    k = 1
    while i - pow(6, k) >= 0:
        dp[i] = min(dp[i], dp[i - pow(6, k)] + 1)
        k += 1
    k = 1
    while i - pow(9, k) >= 0:
        dp[i] = min(dp[i], dp[i - pow(9, k)] + 1)
        k += 1
print(dp[n])