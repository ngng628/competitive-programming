n = int(input())
MOD = 10**9 + 7
power = 1
for i in range(n):
   power *= i + 1
   power %= MOD
print(power)
