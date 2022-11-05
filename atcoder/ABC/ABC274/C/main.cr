# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = [-1_i64].concat(ints)

hash = Hash(Int64, Int64).new
hash[1_i64] = 0_i64
(1..2*n+1).each_with_index do |i|
  puts hash[i]

  unless a[i]?.nil?
    hash[2*i] = hash[a[i]] + 1
    hash[2*i + 1] = hash[a[i]] + 1
  end
end