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





<<<<<<< HEAD
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
=======











class DynamicRangeSum(T)
  getter size : Int32
  @data : Array(T)

  def initialize(n : Int)
    @data = Array(T).new(n){ T.zero }
    @size = @data.size
  end

  def initialize(n : Int, val : T)
    @data = Array(T).new(n){ val }
    @size = @data.size
  end

  def initialize(elems : Enumerable(T))
    @size = elems.size.to_i32
    @data = Array(T).new(@size, T.zero)
    elems.each_with_index{ |x, i| add(i, x) }
  end

  def get(left : Int, right : Int) : T
    raise IndexError.new("`left` and `right` must be 0 <= left <= right <= self.size (#{left}, #{right})") unless 0 <= left && left <= right && right <= @size
    sum(right) - sum(left)
  end

  def get?(left : Int, right : Int) : T?
    return nil unless 0 <= left && left <= right && right <= @size
    get(left, right)
  end

  def get(i : Int) : T
    get(i, i + 1)
  end

  def get?(i : Int) : T?
    get?(i, i + 1)
  end

  {% begin %}
    {% for int1 in Int.union_types + [Nil] %}
      {% for int2 in Int.union_types + [Nil] %}
        def get(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get(left, right)
        end

        def get?(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get?(left, right)
        end

        def [](range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get(left, right)
        end

        def []?(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get?(left, right)
        end
      {% end %}
    {% end %}
  {% end %}

  def [](i : Int) : T; get(i, i + 1) end
  def []?(i : Int) : T?; get?(i, i + 1) end

  def [](l : Int, r : Int) : T; get(l, r) end
  def []?(l : Int, r : Int) : T?; get?(l, r) end

  def []=(i : Int, x : T) : T; add(i, x - get(i)) end

  def set(i : Int, x : T)
    self[i] = x
  end

  def add(i : Int, x : T)
    i += 1
    while (i <= @size)
      @data[i - 1] += x
      i += i & -i
    end
    x
  end

  private def sum(r : Int) : T
    s = T.zero
    while r > 0
      s += @data[r - 1]
      r -= r & -r
    end
    s
  end
end

class SparseTable(T)
  getter size : Int32
  @data : Array(T)
  @table : Array(Array(T))
  @lookup : Array(Int32)
  @op : (T, T) -> T

  def self.max(elems : Enumerable(T))
    new elems, ->(x : T, y : T){ x > y ? x : y }
  end

  def self.min(elems : Enumerable(T))
    new elems, ->(x : T, y : T){ x < y ? x : y }
  end

  def self.bitwise_or(elems : Enumerable(T))
    new elems, ->(x : T, y : T){ x | y }
  end

  def self.bitwise_and(elems : Enumerable(T))
    new elems, ->(x : T, y : T){ x & y }
  end

  def self.gcd(elems : Enumerable(T))
    new elems, ->(x : T, y : T){ x.gcd(y) }
  end

  def initialize(elems : Enumerable(T), @op : (T, T) -> T)
    @size = elems.size
    @data = Array(T).new
    log = (0..).index{ |k| (1 << k) > @size }.not_nil!

    @table = Array.new(log){ Array(T).new(1 << log, T.zero) }
    elems.each_with_index{ |e, i| @table[0][i] = e; @data << e }

    (1...log).each do |i|
      j = 0
      while j + (1 << i) <= (1 << log)
        @table[i][j] = @op.call(@table[i - 1][j], @table[i - 1][j + (1 << (i - 1))])
        j += 1
      end
    end

    @lookup = [0] * (@size + 1)
    (2..@size).each do |i|
      @lookup[i] = @lookup[i >> 1] + 1
    end
  end

  def prod(range : Range(Int?, Int?))
    left = (range.begin || 0)
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end

    b = @lookup[right - left]
    @op.call(@table[b][left], @table[b][right - (1 << b)])
  end

  def prod?(range : Range(Int?, Int?))
    left = (range.begin || 0)
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end

    return nil unless 0 <= left && left <= right && right <= @size
    prod(range)
  end

  def [](i)
    @data[i]
  end

  def []?(i)
    @data[i]?
  end

  def [](range : Range(Int?, Int?))
    prod(range)
  end

  def []?(range : Range(Int?, Int?))
    prod?(range)
  end
end

class EulerTourTree
  @size : Int32
  @graph : Array(Array(Int32))
  @time : Int32

  getter itinerary : Array(Int32)
  getter login : Array(Int32)
  getter logout : Array(Int32)

  getter parents : Array(Int32)
  getter depths : Array(Int32)

  @min_depth : SparseTable(Int32)

  # n 頂点 0 辺のグラフを生成します。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # ```
  def initialize(n : Int)
    @size = n.to_i32
    @graph = Array.new(n) { [] of Int32 }
    @time = 0

    @itinerary = [] of Int32
    @login = [-1] * n
    @logout = [-1] * n

    @parents = [-1] * n
    @depths = [] of Int32
    @min_depth = uninitialized SparseTable(Int32)
  end

  # 無向辺 (u, v) を追加します。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.add_edge(u, v)
  # ```
  def add_edge(u : Int, v : Int)
    @graph[u] << v.to_i32
    @graph[v] << u.to_i32
  end

  # 実際にオイラーツアーします。
  #
  # itinerary などが正しく構築されます。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # tree.build(root: 3)
  # ```
  def build(root : Int = 0)
    dfs(root.to_i32, -1, 0)
    @min_depth = SparseTable(Int32).min(@depths)
  end

  # 頂点 u と頂点 v の最小共通祖先を返します。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # tree.lca(u, v)
  # ```
  def lca(u : Int, v : Int)
    l = {@login[u], @logout[u], @login[v], @logout[v]}.min
    r = {@login[u], @logout[u], @login[v], @logout[v]}.max

    mn = @min_depth[l...r]
    ok = r
    ng = l
    while ok - ng > 1
      mid = (ok + ng) // 2
      if @min_depth[l...mid] == mn
        ok = mid
      else
        ng = mid
      end
    end

    @itinerary[ok - 1]
  end

  # 根を x とする部分木の頂点のコストの総和を求めるためのリストを返します。
  #
  # `zero` には「総和」の単位元を渡してください。
  #
  # リストの i 番目には時刻 i に訪れた頂点のコストが格納されています。
  # ただし、その頂点が時刻 i 以前に訪問済みだった場合は zero が格納されます。
  #
  # 頂点 v のコストが w 変更される場合は、
  # このリストの @login[v] 番目を w にすると良いです。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # node_cost = Array.new(n)
  # tree.subtree_node_costs { |v| node_costs[v] }
  # ```
  def subtree_node_costs(zero = U.zero, & : Int32 -> U) forall U
    costs = Array(U).new(itinerary.size) { zero }
    @size.times do |v|
      t = @login[v]
      cost = yield v
      costs[t]
    end
  end

  # 根を x とする部分木の辺のコストの総和を求めるためのリストを返します。
  #
  # `zero` には「総和」の単位元を渡してください。
  #
  # リストの i 番目には時刻 i に訪れた頂点と、
  # 時刻 i - 1 に訪れた頂点を結ぶ辺のコストが格納されています。
  # ただし、その辺が時刻 i 以前に訪問済みだった場合は zero が格納されます
  #
  # 無向辺 (u, v) のコストが w に変更される場合は、
  # 頂点 u, v のうち、**後に**訪れる方の頂点を bwd として、
  # このリストの @login[bwd] 番目を w にすると良いです。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # edge_cost = Hash({Int32, Int32}, Int64).new
  # tree.subtree_edge_costs { |u, v| edge_cost[{u, v}] }
  # ```
  def subtree_edge_costs(zero = U.zero, & : Int32, Int32 -> U) forall U
    costs = Array(U).new(itinerary.size) { zero }
    @size.times do |v|
      t = @login[v]
      next if t == 0
      par = @parents[v]
      costs[t] = yield par, v
    end
  end

  # 根からのパスに現れる頂点のコストの総和を求めるためのリストを返します。
  #
  # リストの i 番目には時刻 i に訪れた頂点のコストが格納されています。
  # ただし、その頂点が時刻 i 以前に訪問済みだった場合は、マイナス倍された値が格納されます。
  #
  # 頂点 v のコストが w 変更される場合は、
  # このリストの @login[v] 番目を w に、それ以降で v が現れる時刻番目を -w にすると良いです。
  # （つまり、計算量がそこそこかかりそう？）
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # tree.node_costs_on_root_path { |v| node_costs[v] }
  # ```
  def node_costs_on_root_path(& : Int32 -> U) forall U
    root = itinerary[0]
    costs = Array(U).new(itinerary.size + 1)
    costs << yield root
    (itinerary.size - 1).times do |i|
      s = itinerary[i]
      t = itinerary[i + 1]
      if @parents[t] == s
        costs << yield t
      else
        costs << -(yield s)
      end
    end
    costs << -(yield root)
  end

  # 根からのパスに現れる辺のコストの総和を求めるためのリストを返します。
  #
  # `zero` には「総和」の単位元を渡してください。
  #
  # リストの i 番目には時刻 i に訪れた頂点と、
  # 時刻 i - 1 に訪れた頂点を結ぶ辺のコストが格納されています。
  # ただし、その辺が時刻 i 以前に訪問済みだった場合は、マイナス倍された値が格納されます。
  # また、時刻 0 と時刻 itinerary.size には zero が格納されます。
  #
  # 辺 (u, v) のコストが w 変更される場合は、
  # 頂点 u, v のうち、**後に**訪れる方の頂点 bwd をとして、
  # このリストの @login[bwd] 番目を w に、@logout[bwd] 番目を -w にしてください。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # tree.edge_costs_on_root_path { |u, v| edge_cost[{u, v}] }
  # ```
  def edge_costs_on_root_path(zero = U.zero, & : Int32, Int32 -> U) forall U
    root = itinerary[0]
    costs = Array(U).new(itinerary.size + 1)
    costs << U.zero
    (itinerary.size - 1).times do |i|
      s = itinerary[i]
      t = itinerary[i + 1]
      if @parents[t] == s
        costs << yield s, t
      else
        costs << -(yield s, t)
      end
    end
    costs << U.zero
  end

  # 根を subroot とする部分木の頂点のコストの総和を返します。
  #
  # ブロックでは整数 l, r が与えられるので、
  # subtree_node_costs の [l, r) までの総和を返してください。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # node_cost = Array.new(n)
  # costs = tree.subtree_node_costs { |v| node_costs[v] }
  # csum = StaticRangeSum.new(costs)
  # tree.sum_subtree_node_cost(subroot: 3) { |l, r| csum[l...r] }
  # ```
  def sum_subtree_node_cost(subroot : Int, & : Int32, Int32 -> U) forall U
    l = @login[subroot]
    r = @logout[subroot]
    yield l, r
  end

  # 根を subroot とする部分木の辺のコストの総和を返します。
  #
  # ブロックでは整数 l, r が与えられるので、
  # subtree_edge_costs の [l, r) までの総和を返してください。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # edge_cost = Hash({Int32, Int32}, Int64).new
  # costs = tree.subtree_node_costs { |u, v| edge_cost[{u, v}] }
  # csum = StaticRangeSum.new(costs)
  # tree.sum_subtree_edge_cost(subroot: 3) { |l, r| csum[l...r] }
  # ```
  def sum_subtree_edge_cost(subroot : Int, & : Int32, Int32 -> U) forall U
    l = @login[subroot]
    r = @logout[subroot]
    yield l + 1, r
  end

  # 根から頂点 v へのパスに現れる頂点のコストの総和を返します。
  #
  # ブロックでは整数 l, r が与えられるので、
  # root_path_node_costs の [l, r) までの総和を返してください。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # costs = tree.root_path_node_costs { |v| node_costs[v] }
  # csum = StaticRangeSum.new(costs)
  # tree.sum_node_cost_on_path_to(v: 3) { |l, r| csum[l...r] }
  # ```
  def sum_node_cost_on_path_to(v : Int, & : Int32, Int32 -> U) forall U
    r = @login[v]
    yield 0, r + 1
  end

  # 根から頂点 v へのパスに現れる辺のコストの総和を返します。
  #
  # ブロックでは整数 l, r が与えられるので、
  # root_path_edge_costs の [l, r) までの総和を返してください。
  #
  # ```
  # tree = EulerTourTree.new(n)
  # tree.build
  # costs = tree.root_path_node_costs { |v| node_costs[v] }
  # csum = StaticRangeSum.new(costs)
  # tree.sum_edge_cost_on_path_to(v: 3) { |l, r| csum[l...r] }
  # ```
  def sum_edge_cost_on_path_to(v : Int, & : Int32, Int32 -> U) forall U
    r = @login[v]
    yield 1, r + 1
  end

  private def dfs(v : Int32, par : Int32, d : Int32)
    @itinerary << v
    @depths << d
    @parents[v] = par
    @login[v] = @time
    @time += 1

    @graph[v].each do |child|
      next if child == par
      dfs(child, v, d + 1)

      @itinerary << v
      @depths << d
    end
    
    @logout[v] = @time
    @time += 1
>>>>>>> master
  end
end
