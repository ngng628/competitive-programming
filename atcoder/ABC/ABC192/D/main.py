# ────────────────────────
#  入力
# ────────────────────────
x = input()
m = int(input())
d = int(max(x))

# ────────────────────────
#  コーナーケース
# ────────────────────────
if len(x) == 1:
    x = int(x)
    if x <= m: print(1)
    else: print(0)
    exit(0)

# ────────────────────────
#  二分探索
# ────────────────────────
def isOK(s, base):
   res = 0
   n = len(s)
   r = 1
   for i in range(n)[::-1]:
      res += int(s[i]) * r
      if res > m: return False
      if r > m: return False
      r *= base
   return True;

if not isOK(x, d+1):
   print(0)
   exit(0)
ok = d+1
ng = 10**18 + 10

while abs(ok - ng) > 1:
   mid = (ok + ng) // 2
   if isOK(x, mid): ok = mid
   else: ng = mid

# ────────────────────────
#  出力
# ────────────────────────
print(ok - d)