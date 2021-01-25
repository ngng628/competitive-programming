import math
n = int(input())
ans = n
#for i in range(n-1, 1, -1):
for i in range(2, n):
  if ans % i == 0:
    print("i:", i)
    continue
  ans *= i
ans += 1

for i in range(2, n+1):
  if ans % i != 1:
    print("oasidjfoiasjdf")
if ans > 10**13:
  print("桁数:", math.log10(ans))
  print("over")

print(ans)
