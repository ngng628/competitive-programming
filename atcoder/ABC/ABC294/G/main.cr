# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

struct Edge
  @data : {Int64, Int64}
  def initialize(t : Int64, w : Int64)
    @data = {t, w}
  end

  def self.to; @data[0] end
  def self.weight; @data[1] end
  def [](i : Int); @data[i] end
end
alias Edges = Array(Edge)
alias Graph = Array(Edges)

class Edge2
  property from : Int64
  property to : Int64
  property weight : Int64
  def initialize(@from, @to, @weight)
  end
end

n = int
edges = Array(Edge2).new(n - 1) { Edge2.new(0_i64, 0_i64, 0_i64) }
graph = Array.new(n) { [] of Edge }
(n - 1).times do |i|
  u, v, w = ints
  u -= 1; v -= 1
  graph[u] << Edge.new(v, w)
  graph[v] << Edge.new(u, w)
  edges[i] = Edge2.new(u, v, w)
end

lca = LCA.new(graph)

q = int
threshold = Math.sqrt(q).to_i
wj = Hash(Int64, Int64).new
q.times do
  t, a, b = ints
  case t
  when 1
    wj[a - 1] = b
  when 2
    a -= 1; b -= 1
    ans = lca.distance_between(a, b)
    wj.each do |index, weight|
      u = edges[index].from
      v = edges[index].to
      w = edges[index].weight
      if lca.on_path?(a, b, u) && lca.on_path?(a, b, v)
        ans -= w
        ans += weight
      end
    end
    puts ans
  end

  # 更新
  if threshold < wj.size
    wj.each do |index, w|
      edges[index].weight = w
    end

    graph = Array.new(n) { [] of Edge }
    edges.each_with_index do |edge, i|
      u = edge.from
      v = edge.to
      w = edge.weight

      graph[u] << Edge.new(v, w)
      graph[v] << Edge.new(u, w)
    end

    lca = LCA.new(graph)
    wj = Hash(Int64, Int64).new
  end
end





class LCA
  getter parent : Array(Array(Int64))
  getter dist : Array(Int64)
  getter dist2 : Array(Int64)
  @graph : Graph

  def initialize(@graph : Graph, root = 0_i64)
    n = graph.size
    k = 1_i64
    while (1_i64 << k) < n
      k += 1
    end

    @parent = Array.new(k){ Array.new(n, -1_i64) }
    @dist = Array.new(n, OO)
    @dist2 = Array.new(n, OO)
    dfs(root, -1_i64, 0_i64, 0_i64)
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
    if @dist2[u] < @dist2[v]
      u, v = v, u
    end
    n = @parent.size
    n.times do |k|
      u = @parent[k][u] if (dist2[u] - dist2[v]) >> k & 1 > 0
    end
    return u if u == v
    n.times do |k|
      if @parent[n-k-1][u] != @parent[n-k-1][v]
        u, v = @parent[n-k-1][u], @parent[n-k-1][v]
      end
    end
    @parent[0][u]
  end

  def distance_between(u : Int, v : Int) : Int64
    dist[u] + dist[v] - dist[ancestor(u, v)] * 2
  end

  def distance_between2(u : Int, v : Int) : Int64
    dist2[u] + dist2[v] - dist2[ancestor(u, v)] * 2
  end

  def on_path?(u : Int, v : Int, a : Int) : Bool
    distance_between2(u, a) + distance_between2(a, v) == distance_between2(u, v)
  end

  private def dfs(root : Int64, par : Int64, d : Int64, d2)
    @parent[0][root] = par
    @dist[root] = d
    @dist2[root] = d2
    @graph[root].each do |(child, w)|
      dfs(child, root, d + w, d2 + 1) unless child == par
    end
  end
end
