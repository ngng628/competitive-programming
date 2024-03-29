# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i32 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i32 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints

rec = uninitialized Int32, Array(Int32) -> Int32
rec = ->(k : Int32, seq : Array(Int32)) do
  if k == -1
    return seq.min
  end

  if seq.all?{ |e| e.bit(k) == 0 }
    return rec.call(k - 1, seq)
  elsif seq.all?{ |e| e.bit(k) == 1 }
    return rec.call(k - 1, seq.map{ |e| e ^ (1 << k) })
  else
    g = seq.group_by{ |e| e.bit(k) }
    return Math.min(rec.call(k - 1, g[0]) | (1 << k), rec.call(k - 1, g[1]))
  end
end

ans = rec.call(31, a)
puts ans