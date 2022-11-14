# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, k = ints
length = Array.new(n){ 0_i64 }
init = Array.new(n){ 0_i64 }
diff = Array.new(n){ 0_i64 }
n.times do |i|
  length[i], init[i], diff[i] = ints
end

ans = (0_i64..OO).bsearch do |num|
  s = n.times.sum{ |i| init[i] > num ? 0_i64 : Math.min((num - init[i]) // diff[i] + 1, length[i]) }
  s >= k
end

puts ans