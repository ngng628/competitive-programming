# ────────────────────────
#  入力
# ────────────────────────
x = input()
m = int(input())
d = int(max(x))
n = len(x)

# ────────────────────────
#  二分探索
# ────────────────────────
def isOK(base):
    res = 0
    r = 1
    for i in range(n)[::-1]:
        res += int(x[i]) * r
        if res > m or r > m:
            return False
        r *= base
    return True

ok = 0
ng = 10**18 + 2

while abs(ok - ng) > 1:
    mid = (ok + ng) // 2
    if isOK(mid):
        ok = mid
    else:
        ng = mid

# ────────────────────────
#  出力
# ────────────────────────
if ng == 10**18 + 2:
    print(1)
else:
    print(max(0, ok - d))
