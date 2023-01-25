# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

s = str.chars
n = s.size



def f(len)

end

ans = 0_i64
base = 26_i64
exp = 0_i64
t = s.reverse
n.times do |i|
  x = i == 0 ? t[i].ord - 'A'.ord : t[i].ord - 'A'.ord + 1

  ans += (base**exp) * x
  exp += 1
end

puts ans + 1