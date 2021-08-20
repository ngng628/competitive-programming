n = int(input())

for k in range(10**7):
   if 2**k > n:
      print(k - 1)
      exit()