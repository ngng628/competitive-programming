# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, k = ints
c = ints
p = ints
order = (0_i64...n).to_a.sort_by{ |i| p[i] }

hash = Hash(Int64, Int64).new
order.each do |i|
  hash[c[i]] = OO unless hash.has_key?(c[i])
  hash[c[i]] = Math.min(hash[c[i]], p[i])
  break if hash.size >= k
end

if hash.size < k
  puts "-1"
else
  puts hash.sum{ |k, v| v }
end