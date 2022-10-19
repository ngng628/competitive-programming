# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
k = Array(Int64).new(m){ 0_i64 }
x = Array(Set(Int64)).new(m){ Set(Int64).new }
m.times do |i|
  line = ints -1
  k[i] = line[0] + 1
  x[i] = Set.new line[1..]
end

ans = n.times.all? do |i|
  (i + 1...n).all? do |j|
    m.times.any? do |t|
      i.in?(x[t]) && j.in?(x[t])
    end
  end
end

puts ans ? "Yes" : "No"