# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = Array.new(n){ 0_i64 }
b = Array.new(n){ 0_i64 }
n.times do |i|
  a[i], b[i] = ints
end

f, g = (a + b + [1_i64]).mapping

v = f.size
graph = Array.new(v){ Array(Int64).new }
n.times do |i|
  graph[f[a[i]]] << f[b[i]]
  graph[f[b[i]]] << f[a[i]]
end

que = Deque(Int64).new [0_i64]
dist = Array.new(v){ |i| i == 0_i64 ? 0_i64 : OO }
until que.empty?
  from = que.shift
  graph[from].select{ |v| dist[v] == OO }.each do |to|
    dist[to] = dist[from] + 1
    que << to
  end
end

(0...v).reverse_each do |i|
  if dist[i] != OO
    puts g[i]
    break
  end
end





class Array(T)
  def compress
    b = clone.sort.uniq
    f, g = Hash(Int64, Int64).new, Hash(Int64, Int64).new
    map{ |s| b.bsearch_index{ |x| x >= s } || b.size }
  end

  def mapping
    b = clone.sort.uniq
    f, g = Hash(Int64, Int64).new, Hash(Int64, Int64).new
    each do |s|
      index = b.bsearch_index{ |x| x >= s } || b.size
      f[s.to_i64] = index.to_i64
      g[index.to_i64] = s.to_i64
    end
    {f, g}
  end
end