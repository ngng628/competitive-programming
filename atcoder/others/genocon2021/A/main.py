m = int(input())
R = {
   'A': 'T',
   'C': 'G',
   'G': 'C',
   'T': 'A',
}

for i in range(m):
   for a in reversed(input()):
      print(R[a], end='')
   print()