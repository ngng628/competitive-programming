# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

t = int
t.times do
  ans = 0_i64
  n2, n3, n4 = ints
  # 3 と 4 のペアをなるべく作る
  want = n3 // 2
  can = Math.min(want, n4)
  ans += can
  n4 -= can
  n3 -= can * 2

  # 2 と 4 のペアをなるべく作る
  want = n4 // 2
  can = Math.min(want, n2)
  ans += can
  n2 -= can
  n4 -= can * 2

  # 2 と 3 のペアをなるべく作る
  want = n3 // 2
  can = Math.min(want, n2 // 2)
  ans += can
  n3 -= can * 2
  n2 -= can * 2

  # 2 と 4 のペアをなるべく作る
  want = n2 // 3
  can = Math.min(want, n4)
  ans += can
  n4 -= can
  n2 -= can * 3

  # 2 だけで作る
  can = n2 // 5
  ans += can

  puts ans
end