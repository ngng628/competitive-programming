from bisect import bisect_right

n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
a.append(0)
sums = sorted([e1 + e2 for e1 in a for e2 in a])

ans = 0
for s in sums:
  if m - s < 0:
    break
  ans = max(ans, s + sums[bisect_right(sums, m - s) - 1])

print(ans)
