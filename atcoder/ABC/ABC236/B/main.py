n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))

cnt = [0 for i in range(n)]
for i in a:
   cnt[i] += 1

for i in range(n):
   if cnt[i] == 3:
      print(i + 1)
      exit(0)