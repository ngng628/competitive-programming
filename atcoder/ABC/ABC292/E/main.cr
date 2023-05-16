# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
bfs = BfsGraph.new(n)
graph = Array.new(n) { [] of Int64 }
rev = Array.new(n) { [] of Int64 }
edges = Set({Int64, Int64}).new
m.times do
  u, v = ints -1
  bfs.add_edge(u, v, directed: false)
  graph[u] << v
  rev[v] << u
  edges << {u, v}
end

dist = bfs.shortest_path

ans = 0_i64
n.times do |from|
  n.times do |to|
    next if from == to
    if dist[from][to] < OO && dist[from][to] != 1
      ans += 1
    end
  end
end

puts ans


class BfsGraph
  getter size : Int32
  getter graph : Array(Array(Int32))

  # n 頂点 0 辺からなるグラフを作成します。
  #
  # ```
  # graph = BfsGraph.new(n)
  # ```
  def initialize(n : Int)
    @size = n.to_i32
    @graph = Array.new(@size){ Array(Int32).new }
  end

  # 辺 (u, v) を追加します。
  #
  # `directed` が `true` の場合、
  # 無向グラフとみなして、両端から辺を生やします。
  #
  # ```
  # graph = BfsGraph.new(n)
  # graph.add_edge(u, v) # => (u) <---w---> (v)
  # graph.add_edge(u, v, directed: false) # => (u) ----w---> (v)
  # ```
  def add_edge(u : Int, v : Int, directed : Bool = true)
    @graph[u.to_i32] << v.to_i32
    @graph[v.to_i32] << u.to_i32 if directed
  end

  # 全点対間の最短経路長を返します。
  #
  # ```
  # dists = graph.shortest_path
  # dists # => [[0, 1, 3], [1, 0, 2], [1, 1, 0]]
  # ```
  def shortest_path
    (0...@size).map{ |s| shortest_path(s) }
  end

  # 始点 `start` から各頂点への最短経路長を返します。
  #
  # ```
  # dist = graph.shortest_path(start: 2)
  # dist # => [3, 8, 0, 7, 1]
  # ```
  def shortest_path(start : Int)
    queue = Deque.new([start.to_i32])
    dist = Array.new(@size){ |i| i == start ? 0_i64 : OO }
    until queue.empty?
      from = queue.shift
      @graph[from].each do |to|
        next if dist[to] != OO
        dist[to] = dist[from] + 1
        queue << to
      end
    end
    dist
  end

  # 始点 `start` から終点 `dest` への最短経路長を返します。
  #
  # ```
  # dist = graph.shortest_path(start: 2, dest: 0)
  # dist # => 12
  # ```
  def shortest_path(start : Int, dest : Int)
    shortest_path(start)[dest]
  end
end

class DisjointSet
  @n : Int32
  @parent_or_size : Array(Int32)

  def initialize
    @n = 0
    @parent_or_size = Array(Int32).new
  end

  def initialize(size : Int)
    @n = size.to_i32
    @parent_or_size = [-1] * size
  end

  def unite(a : Int, b : Int) : Int32
    x = leader(a)
    y = leader(b)
    return x if x == y
    if -@parent_or_size[x] < -@parent_or_size[y]
      x, y = y, x
    end
    @parent_or_size[x] += @parent_or_size[y]
    @parent_or_size[y] = x
    x
  end

  def equiv?(a : Int, b : Int) : Bool
    leader(a) == leader(b)
  end

  def leader(a : Int) : Int32
    return a.to_i32 if @parent_or_size[a] < 0
    @parent_or_size[a] = leader(@parent_or_size[a])
    @parent_or_size[a]
  end

  def size(a : Int) : Int32
    -@parent_or_size[leader(a)]
  end

  def groups : Array(Array(Int32)) | Nil
    leader_buf = [0] * @n
    group_size = [0] * @n
    @n.times do |i|
      leader_buf[i] = leader(i)
      group_size[leader_buf[i]] += 1
    end
    res = Array.new(@n){ [] of Int32 }
    @n.times do |i|
      res[leader_buf[i]] << i
    end
    res.delete([] of Int32)
    res
  end
end
