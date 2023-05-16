# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, t = ints
c = ints
r = ints

same = [] of {Int64, Int64}
n.times do |i|
  if c[i] == t
    same << {r[i], i + 1}
  end
end

if same.size >= 1
  puts same.max_by(&.[0])[1]
else
  t = c[0]
  same = [] of {Int64, Int64}
  n.times do |i|
    if c[i] == t
      same << {r[i], i + 1}
    end
  end
  puts same.max_by(&.[0])[1]
end