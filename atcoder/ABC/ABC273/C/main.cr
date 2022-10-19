# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints

b = a.uniq.sort

# ai よりも大きいものは何種類ですか？
ans = Array.new(n + 1){ 0 }
n.times do |i|
  t = b.size - (b.bsearch_index{ |x| x > a[i] } || b.size)
  ans[t] += 1
end

n.times{ |i| puts ans[i] }