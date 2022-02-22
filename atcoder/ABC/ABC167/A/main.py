s = input()
t = input()
if (len(s) + 1 == len(t)):
   ok = True
   for i in range(len(s)):
      if s[i] != t[i]:
         ok = False
   if ok:
      print('Yes')
      exit(0)
print('No')
