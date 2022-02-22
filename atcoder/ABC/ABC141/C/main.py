n, K, Q = map(int, input().split())
a = [int(input()) - 1 for _ in range(Q)]
cnt = [0 for _ in range(n)]
for i in a:
   cnt[i] += 1
points = [K - Q + cnt[i] for i in range(n)]
for p in points:
   print('Yes' if p > 0 else 'No')