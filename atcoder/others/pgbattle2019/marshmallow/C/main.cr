# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
pins = Array.new(10**5 + 10){ |i| 1 <= i && i <= m ? 1_i64 : 0_i64 }

(1..n).each do |i|
  a, b = ints
  begin
    j = i - a - b
    j = -OO if j < 0
    pins[i - a - b] = 0
  rescue
  end
end

puts m - pins.sum