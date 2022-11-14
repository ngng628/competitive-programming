# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints
cnt = Array.new(4){ Array.new(n){ 0 } }
c = (a.map_with_index do |v, i|
  [2, 3].each do |d|
    while v % d == 0
      cnt[d][i] += 1
      v //= d
    end
  end
  v
end).uniq.size

unless c == 1
  puts "-1"
  exit
end

ans = [2, 3].sum do |d|
  until cnt[d].any?{ |v| v == 0 }
    n.times{ |i| cnt[d][i] -= 1 }
  end
  cnt[d].sum
end

puts ans