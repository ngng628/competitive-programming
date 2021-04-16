buff = [0] * 10
ptr = 0
for c in input():
   if c == '0':
      buff[ptr] = '0'
      ptr += 1
   if c == '1':
      buff[ptr] = '1'
      ptr += 1
   if c == 'B':
      ptr = max(0, ptr - 1)

for i in range(ptr):
   print(buff[i], end = '' if i < ptr - 1 else '\n')