# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

record Cell, r : Int64, c : Int64, a : Int64

h, w, n = ints
cells = Array.new(n){ |i| r, c, a = ints; {Cell.new(r - 1, c - 1, a), i} }.sort_by{ |e| e[0].a }.reverse

rows = [0_i64] * h
cols = [0_i64] * w
acc_rows = [] of {Int64, Int64}
acc_cols = [] of {Int64, Int64}

ans = [0_i64] * n
old = nil
cells.each do |(cell, index)|
  if old != cell.a
    old = cell.a
    acc_rows.each{ |r, nxt| chmax(rows[r], nxt) }
    acc_cols.each{ |c, nxt| chmax(cols[c], nxt) }
    acc_rows = [] of {Int64, Int64}
    acc_cols = [] of {Int64, Int64}
  end
  ans[index] = Math.max(rows[cell.r], cols[cell.c])
  acc_rows << {cell.r, ans[index] + 1}
  acc_cols << {cell.c, ans[index] + 1}
end

puts ans.join("\n")