a, b = map(int, input().split())
if a == 1 and b == 10:
   print('Yes')
   exit(0)
elif a == 10 and b == 1:
   print('Yes')
   exit(0)

a -= 1
b -= 1
if (max(a, b) - min(a, b) % 10) == 1:
   print('Yes')
else:
   print('No')