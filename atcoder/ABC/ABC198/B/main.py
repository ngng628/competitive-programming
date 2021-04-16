n = input()
def ok(s):
   for i in range(len(s)):
      if s[i] != s[len(s) - i - 1]:
         return False
   return True

for i in range(20):
   zero = '0' * i
   if ok(zero + n):
      print('Yes')
      exit(0)

print('No')