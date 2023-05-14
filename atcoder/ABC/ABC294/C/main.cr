# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
a = ints.map_with_index { |ai, i| {ai, i} }
b = ints.map_with_index { |bi, i| {bi, i + n} }

c = (a + b).sort
ans = {[-1] * n, [-1] * m}
(n + m).times do |i|
  if c[i][1] < n
    ans[0][c[i][1]] = i.to_i32 + 1
  else
    ans[1][c[i][1] - n] = i.to_i32 + 1
  end
end

puts ans[0].join(" ")
puts ans[1].join(" ")



