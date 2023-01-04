# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = (1..n).map{ ints }

fi = Array.new(n){ Array.new(n){ [] of Int64 } }

isdiag = ->(i : Int64, j : Int64) do
  i + j == n - 1
end

rec = uninitialized Int64, Int64, Int64 -> Nil
rec = ->(i : Int64, j : Int64, acc : Int64) do
  if isdiag.call(i, j)
    fi[i][j] << acc
    return
  end
  rec.call(i + 1, j, acc ^ a[i][j]) if i + 1 < n
  rec.call(i, j + 1, acc ^ a[i][j]) if j + 1 < n
end
rec.call(0_i64, 0_i64, 0_i64)

se = Array.new(n){ Array.new(n){ Hash(Int64, Int64).new(0_i64) } }
rec2 = uninitialized Int64, Int64, Int64 -> Nil
rec2 = ->(i : Int64, j : Int64, acc : Int64) do
  if isdiag.call(i, j)
    se[i][j][acc] += 1
    return
  end
  rec2.call(i - 1, j, acc ^ a[i][j]) if i - 1 >= 0
  rec2.call(i, j - 1, acc ^ a[i][j]) if j - 1 >= 0
end
rec2.call(n - 1, n - 1, 0_i64)

ans = n.times.sum do |i|
  n.times.sum do |j|
    next 0_i64 unless isdiag.call(i, j)
    fi[i][j].sum do |acc|
      f = acc ^ a[i][j]
      se[i][j][f]
    end
  end 
end

puts ans