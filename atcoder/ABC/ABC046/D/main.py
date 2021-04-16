s = input()

def janken(a, b):
   if a == b:
      return 0;
   elif a == 'g':
      return -1
   else:
      return 1

ans = 0
for i in range(len(s)):
   if i % 2 == 0:
      ans += janken('g', s[i])
   else:
      ans += janken('p', s[i])

print(ans)