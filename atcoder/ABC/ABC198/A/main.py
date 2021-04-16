n = int(input())
cnt = 0
for i in range(100):
   a = i
   b = n - i
   if a >= 1 and b >= 1:
      cnt += 1
print(cnt)