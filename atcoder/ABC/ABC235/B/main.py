n = int(input())
h = list(map(int, input().split()))

now = 0
while now + 1 < n and h[now] < h[now + 1]:
   now += 1

print(h[now])
