# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
graph = Array.new(n){ Array.new(n){ 0 } }
m.times do
  u, v = ints -1
  graph[u][v] = graph[v][u] = 1
end

ans = n.times.sum do |a|
  (a+1...n).sum do |b|
    (b+1...n).count do |c|
      graph[a][b] == 1 && graph[b][c] == 1 && graph[c][a] == 1
    end.to_i64
  end.to_i64
end.to_i64

puts ans