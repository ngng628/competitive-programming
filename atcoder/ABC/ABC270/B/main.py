x, y, z = map(int, input().split())

ans = 10**20

# ハンマーを取りに行く
d1 = 0
now = 0
flg = True
cnt = 0
while now != z:
   now += abs(z - now) // (z - now)
   cnt += 1
   if now == y:
      flg = False
      break

# ゴールする
while now != x:
   now += abs(x - now) // (x - now)
   cnt += 1

if flg:
   ans = min(ans, cnt)


# ゴールする
now = 0
cnt = 0
flg = True
while now != x:
   now += abs(x - now) // (x - now)
   cnt += 1
   if now == y:
      flg = False
      break

if flg:
   ans = min(ans, cnt)

print(ans if ans < 10**20 else -1)