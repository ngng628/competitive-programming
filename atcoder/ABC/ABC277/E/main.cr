# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m, k = ints
graph = Graph.new(2*n){ Edges.new }
m.times do
  u, v, w = ints
  u -= 1; v -= 1
  case w
  when 0
    graph.add_edge(u + n, v + n, 1_i64)
  when 1
    graph.add_edge(u, v, 1_i64)
  end
end
s = ints -1
s.each do |si|
  graph.add_edge(si, si + n, 0_i64)
  graph.add_edge(si + n, si, 0_i64)
end
graph.add_edge(n - 1, n*2 - 1, 0_i64)

deque = Deque(Int64).new [0_i64]
dist = Array.new(2*n){ |i| i == 0 ? 0_i64 : OO }
until deque.empty?
  from = deque.shift
  graph[from].each do |edge|
    cost = edge.weight
    if dist[edge.to] > dist[from] + cost
      dist[edge.to] = dist[from] + cost
      if cost == 0
        deque.unshift(edge.to)
      else
        deque.push(edge.to)
      end
    end
  end
end

ans = dist[n - 1]
puts ans == OO ? -1_i64 : ans