# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m, t = ints
a = ints

map = Hash(Int64, Int64).new
m.times do
  x, y = ints
  map[x - 1] = y
end

cur = 0
until cur == n - 1
  t -= a[cur]
  if t <= 0
    puts "No"
    exit
  end
  cur += 1
  t += map[cur] if map.has_key? cur
end

puts "Yes"