n = 2000
print(n)
for i in range(n):
  if i & 1:
    print('N', end='')
  else:
    print('A', end='')
print()
