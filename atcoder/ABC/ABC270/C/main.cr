# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, x, y = ints
x -= 1
y -= 1
graph = Array.new(n){ Array(Int64).new }
(n - 1).times do
  u, v = ints -1
  graph[u] << v
  graph[v] << u
end

que = Deque(Int64).new [x]
dist = Array.new(n){ |i| i == x ? 0_i64 : OO }
pre = Array.new(n){ -1_i64 }
until que.empty?
  from = que.shift
  graph[from].select{ |i| dist[i] == OO }.each do |to|
    dist[to] = dist[from] + 1
    pre[to] = from
    que << to
  end
end

ans = [] of Int64
now = y
until now == -1
  ans << now
  now = pre[now]
end

puts ans.map{ |elem| elem + 1 }.reverse.join(" ")


class LCA
  alias Graph = Array(Array(Int64))
  getter parent : Array(Array(Int64))
  getter dist : Array(Int64)
  @graph : Graph

  def initialize(@graph : Graph, root = 0_i64)
    n = graph.size
    k = 1_i64
    while ((1_i64 << k) < n)
      k += 1
    end

    @parent = Array.new(k){ Array.new(n, -1_i64) }
    @dist = Array.new(n, OO)
    dfs(root, -1_i64, 0_i64)
    (k - 1).times do |i|
      n.times do |v|
        if @parent[i][v] < 0
          @parent[i + 1][v] = -1
        else
          @parent[i + 1][v] = @parent[i][@parent[i][v]]
        end
      end
    end
  end

  def ancestor(u : Int, v : Int) : Int64
    if @dist[u] < @dist[v]
      u, v = v, u
    end
    n = @parent.size
    n.times do |k|
      u = @parent[k][u] if (dist[u] - dist[v]) >> k & 1 > 0
    end
    return u if u == v
    n.times do |k|
      if @parent[n-k-1][u] != @parent[n-k-1][v]
        u, v = @parent[n-k-1][u], @parent[n-k-1][v]
      end
    end
    @parent[0][u]
  end

  def distanceBetween(u : Int, v : Int) : Int64
    dist[u] + dist[v] - dist[ancestor(u, v)] * 2
  end

  def on_path?(u : Int, v : Int, a : Int) : Bool
    distanceBetween(u, a) + distanceBetween(a, v) == distanceBetween(u, v)
  end

  private def dfs(root : Int64, par : Int64, d : Int64)
    @parent[0][root] = par
    @dist[root] = d
    @graph[root].each do |child|
      dfs(child, root, d + 1) unless child == par
    end
  end
end