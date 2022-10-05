# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

pos = (1..4).map{ ints }
ans = 4.times.all? do |i|
  x0, y0 = pos[i]
  x1, y1 = pos[(i + 1) % 4]
  x2, y2 = pos[(i + 2) % 4]
  s = x0*y1 + x1*y2 + x2*y0 - y0*x1 - y1*x2 - y2*x0
  s > 0
end

puts ans ? "Yes" : "No"