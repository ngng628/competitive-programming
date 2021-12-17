s = input()
k = int(input())
n = len(s)

cumsum = [0] * (n + 1)
for i in range(n):
   cumsum[i+1] = cumsum[i] + int(s[i] == '.')

ans = 0
l = 0
for r in range(n):
   while cumsum[r + 1] - cumsum[l] > k:
      l += 1
   ans = max(ans, r - l + 1)

print(ans)