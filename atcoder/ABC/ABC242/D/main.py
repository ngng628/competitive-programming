import sys
input = sys.stdin.readline
s = input()
Q = int(input())
for _ in range(Q):
   t, k = map(int, input().split())

   cur = 0
   offset = 0
   if t > 63:
      cur = 0
      offset = 0
   else:
      ac = 0
      wa = 63
      while wa - ac > 1:
         wj = (wa + ac) // 2
         if wj * 2**t <= k:
            ac = wj
         else:
            wa = wj
      cur = ac
      k -= ac * 2**t

   print(f"k = {k}")
   
