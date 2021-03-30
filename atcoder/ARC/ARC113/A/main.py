K = int(input())
ans = 0
for i in range(1, K+1):
   for j in range(1, K+1):
      if i*j > K:
         break
      for k in range(1, K+1):
         if i*j*k <= K:
            ans += 1
         else:
            break
print(ans)
