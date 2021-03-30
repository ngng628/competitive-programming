a, b, w = map(int, input().split())
w *= 1000
for i in range(1, 10**6 + 1):
   unit = w / i
   if (a <= unit <= b):
      print((w + b - 1) // b, w // a)
      exit(0)
print('UNSATISFIABLE')