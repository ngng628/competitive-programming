s = input().split('.')
if int(s[1][0]) <= 4:
   print(int(s[0]))
else:
   print(int(s[0]) + 1)