a, b, k = map(int, input().split())

cnt = 0
slime = a
while slime < b:
   slime *= k
   cnt += 1

print(cnt)