import sys
input = sys.stdin.readline

while True:
   #─────────────────────────────────────────────
   # Step 1. 集合の入力
   #─────────────────────────────────────────────
   mp= dict()
   while True:
      buff = input()
      if buff == '':
         exit(0)
      a, n = buff.split()
      n = int(n)
      if a == 'R' and n == 0:
         break
      else:
         mp[a] = set(map(int, input().split()))
   U = set()
   for v in mp.values():
      for e in v:
         U.add(e)

   #─────────────────────────────────────────────
   # Step 2. 演算の入力
   #─────────────────────────────────────────────
   s = input() + '#'

   #─────────────────────────────────────────────
   # Step 3. 構文解析
   #─────────────────────────────────────────────
   def Expr(i):
      S, i = Set(i)
      while s[i] != '#':
         if s[i] == 'u':
            T, i = Set(i + 1)
            S = S | T
         elif s[i] == 'i':
            T, i = Set(i + 1)
            S = S & T
         elif s[i] == 'd':
            T, i = Set(i + 1)
            S = S - T
         elif s[i] == 's':
            T, i = Set(i + 1)
            S = S ^ T
         else:
            break
      return S, i

   def Set(i):
      if s[i] == 'c':
         S, i = Set(i + 1)
         return U - S, i
      elif s[i] == '(':
         S, i = Expr(i + 1)
         i += 1
         return S, i
      else:
         S = mp[s[i]]
         i += 1
         return S, i

   #─────────────────────────────────────────────
   # Step 4. 出力
   #─────────────────────────────────────────────
   A, _ = Expr(0)
   if len(A) == 0:
      print('NULL')
   else:
      print(*sorted(list(A)))
