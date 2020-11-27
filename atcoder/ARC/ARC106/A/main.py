N = int(input())

for A in range(1, 100):
  for B in range(1, 100):
    if 3**A + 5**B == N:
      print(A, B)
      exit(0)
print(-1)
