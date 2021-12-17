def msb(x):
   i = 0
   pos = 0
   while x > 0:
      if x & 1:
         pos = i
      x //= 2
      i += 1
   return pos

def bit(x):
   return 1 << x

N, L, R = map(int, input().split())

def f(i):
   ml = msb(L)
   mr = msb(R)
   if bit(ml) > bit(i) or bit(mr) < bit(i):
      return 0
   elif i == ml and ml == mr:
      return R - L + 1
   elif i == ml:
      return bit(i + 1) - L
   elif i == mr:
      return R - bit(i) + 1
   else:
      return bit(i + 1) - bit(i)

ans = sum(f(i) for i in range(64) if N & bit(i))
print(ans)
