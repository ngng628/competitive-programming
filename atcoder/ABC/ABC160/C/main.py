k, n = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
ans = 10**100
for i in range(n):
   j = (i + 1) % n
   ans = min(ans, k - min(pow(a[i] - a[j], 1, k), pow(a[j] - a[i], 1, k)))
print(ans)
