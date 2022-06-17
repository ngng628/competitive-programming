n = int(input())
dp = [[0 for _1 in range(n + 1)] for _2 in range(n + 1)]

for i in range(n):
   for j in range(i + 1):
      if i == j or j == 0:
         dp[i][j] = 1
      else:
         dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
      if j != 0:
         print(' ', end='')
      print(dp[i][j], end='')
   print()