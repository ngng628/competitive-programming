# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
s = (1..n).map{ str.chars }
ans = s.all? do |si|
  si[0].in?({'H', 'D', 'C', 'S'}) && si[1].in?({'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'})
end

ans &= n.times.all? do |i|
  n.times.reject{ |j| i == j }.all? do |j|
    s[i] != s[j]
  end
end

puts ans ? "Yes" : "No"