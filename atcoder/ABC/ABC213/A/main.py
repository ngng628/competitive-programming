a, b = map(int, input().split())
for c in range(1000000):
   if a ^ c == b:
      print(c)
      exit(0)