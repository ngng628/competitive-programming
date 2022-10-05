# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int64, b : Int64) : Int64; a < b ? a : b end
def max(a : Int64, b : Int64) : Int64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
          {-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, x, y, z = ints
a2 = ints
b2 = ints
ab = n.times.map{ |i| {a2[i] + b2[i], -i} }.to_a.sort{ |x, y| y <=> x }
a = a2.map_with_index{ |x, i| {x, -i} }.sort{ |x, y| y <=> x }
b = b2.map_with_index{ |x, i| {x, -i} }.sort{ |x, y| y <=> x }

goukaku = Set(Int32).new
a.each do |ai, i|
  break if goukaku.size == x
  goukaku << i
end


b.each do |bi, i|
  break if goukaku.size == x + y
  goukaku << i
end

ab.each do |abi, i|
  break if goukaku.size == x + y + z
  goukaku << i.to_i
end

ans = goukaku.to_a.map{ |i| -i + 1 }.sort
puts ans.join("\n")