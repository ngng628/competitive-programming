t1, t2 = map(int, input().split())
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

# t1 分での距離
da1 = a1 * t1
db1 = b1 * t1

if da1 > db1:
   da1, db1 = db1, da1
   a1, b1 = b1, a1
   a2, b2 = b2, a2
d1 = db1 - da1
assert(d1 >= 0)

# t2 分での距離
da2 = a2 * t2
db2 = b2 * t2
d2 = db2 - da2

# t1 と t2 の差
# すなわち、1 サイクルでどれだけ差が広がるか
sa = d1 + d2
if sa < 0:
   sa = abs(sa)
   # k サイクル目にどれだけ差が広がってしまうか = k*sa
   # k*sa > d1 ったら終わり
   # k*sa <= d1 ったら終わりを満たす最大の k は？
   k = d1 // sa
   cnt = 2*k

   # k サイクル目のお互いの場所
   xa = k * (da1 + da2)
   xb = k * (db1 + db2)
   xa2 = xa + da1
   xb2 = xb + db1
   if xb2 >= xa2 and d1 % sa != 0:
      cnt += 1
   print(cnt)
elif sa == 0:
   print('infinity')
else:
   print(0)