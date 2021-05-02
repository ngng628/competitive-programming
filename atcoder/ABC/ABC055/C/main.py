n, m = map(int, input().split())
ans = 0
if (n > 0):
   ans += min(n, m // 2)
   m = m - 2*ans
ans += m // 4
if m % 4 >= 2 and n % 2 == 1 and n > m // 2:
   ans += 1
print(ans)