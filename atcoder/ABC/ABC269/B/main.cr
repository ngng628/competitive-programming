# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

s = (1..10).map{ str }
h = 10
w = 10
a = OO
b = -1
h.times do |i|
  w.times do |j|
    if s[i][j] == '#'
      chmin(a, 10*i + j)
      chmax(b, 10*i + j)
    end
  end
end

puts "#{a // 10 + 1} #{b // 10 + 1}"
puts "#{a % 10 + 1} #{b % 10 + 1}"