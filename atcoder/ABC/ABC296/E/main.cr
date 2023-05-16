# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints -1

graph = Array.new(n) { [] of Int64 }
selfroop = [false] * n
n.times do |i|
  graph[i] << a[i]
  selfroop[i] = (i == a[i])
end

set = Set(Int64).new
scc = StronglyConnectedComponents.new(graph)
scc.groups.each do |g|
  next if g.size == 1 && !selfroop[g[0]]
  g.each do |member|
    set << member
  end
end

puts set.size




class StronglyConnectedComponents
  alias Graph = Array(Array(Int64))

  getter leader : Array(Int64)
  getter graph : Graph
  getter groups : Array(Array(Int64))
  @n : Int64
  @order : Array(Int64)
  @fwd : Graph
  @bwd : Graph
  @closed : Array(Bool)

  def initialize(@fwd : Graph)
    @n = @fwd.size.to_i64
    @order = Array(Int64).new(@n)
    @leader = Array.new(@n, -1_i64)
    @bwd = Array.new(@n){ Array(Int64).new }
    @n.times do |i|
      @fwd[i].each do |j|
        @bwd[j] << i
      end
    end

    @closed = Array(Bool).new(@n, false)
    @n.times{ |i| dfs(i) }
    @order = @order.reverse
    ptr = rdfs

    @graph = Array.new(ptr){ Array(Int64).new }
    @groups = Array.new(ptr){ Array(Int64).new }
    @n.times do |i|
      @groups[@leader[i]] << i
      @fwd[i].each do |j|
        x, y = @leader[i], @leader[j]
        next if x == y
        @graph[x] << y
      end
    end
  end

  def same(u : Int, v : Int)
    leader[u] == leader[v]
  end

  def size
    @groups.size
  end

  def size(v : Int)
    @groups[leader[v]].size
  end

  private def dfs(i : Int)
    return if @closed[i]
    @closed[i] = true
    @fwd[i].each{ |j| dfs(j) }
    @order << i
  end

  private def rdfs
    ptr = 0_i64
    closed = Array.new(@n, false)
    @order.each do |s|
      next if closed[s]
      que = Deque(Int64).new
      que << s
      closed[s] = true
      @leader[s] = ptr
      until que.empty?
        now = que.shift
        @bwd[now].each do |nxt|
          next if closed[nxt]
          closed[nxt] = true
          @leader[nxt] = ptr
          que << nxt
        end
      end
      ptr += 1
    end
    ptr
  end
end

class BinaryLifting(T)
  getter size : Int32
  @lim : UInt64
  @log : Int32
  @table : Array(Array({Int32, T}))
  @should_build : Bool

  # n 頂点 0 辺のグラフを作ります。
  #
  # 移動回数の上限を limit で指定します。
  # initial でノードの初期値を指定します。
  #
  # ```
  # n = 10
  # graph = BinaryLifting.new(n)
  # ```
  def initialize(n : Int, limit : Int = UInt64::MAX // 2, initial : T = T.zero)
    @size = n.to_i32
    @lim = limit.to_u64
    @log = impl_log2(limit)
    @table = Array.new(n){ Array.new(@log){ {-1, T.zero} } }
    @should_build = true
  end

  # n 頂点 n 辺のグラフを作ります。
  #
  # ブロックで各 i に対する移動先と重みをタプルで返す必要があります。
  #
  # 移動回数の上限を limit で指定します。
  # initial でノードの初期値を指定します。
  #
  # ```
  # n = 10
  # graph = BinaryLifting.new(n){ |i| {a[i].to_i32, 0} }
  # ```
  def initialize(n : Int, limit : Int = UInt64::MAX // 2, initial : T = T.zero, & : Int32 -> {Int32, T})
    @size = n.to_i32
    @lim = limit.to_u64
    @log = impl_log2(limit)
    @table = Array.new(n){ |i| Array.new(@log){ |j| j == 0 ? (yield i) : {-1, T.zero} } }
    @should_build = true
  end

  # 頂点 s から頂点 t に重み weight の辺を追加します。
  #
  # ```
  # n = 10
  # graph = BinaryLifting.new(n){ |i| {a[i].to_i32, 0} }
  # graph.add_edge(0, 1, 10)
  # graph.add_edge(1, 5, 3)
  # graph.add_edge(5, 1, 2)
  # ```
  def add_edge(s : Int, t : Int, weight : T = T.zero)
    @table[s][0] = {t.to_i32, weight}
    @should_build = true
  end

  # query　が高速にできるよう、データを構築します。
  def build
    (0...@log - 1).each do |k|
      @size.times do |i|
        pre = @table[i][k][0]
        if pre == -1
          @table[i][k + 1] = @table[i][k]
        else
          nxt = @table[pre][k][0]
          w = @table[i][k][1] + @table[pre][k][1]
          @table[i][k + 1] = {nxt, w}
        end
      end
    end
    @should_build = false
  end

  # 頂点 start から times 回移動したときいる場所を返します。
  #
  # ```
  # n = 3
  # graph = BinaryLifting.new(n)
  # graph.add_edge(0, 1, 1)
  # graph.add_edge(1, 2, 10)
  # graph.add_edge(2, 1, 100)
  #
  # graph.where(start: 0, times: 5) # => 2
  # graph.where(start: 1, times: 5) # => 0
  # ```
  def where(start : Int, times : Int)
    build if @should_build
    query(start, times)[1]
  end

  # 頂点 start から times 回移動したときいる場所を返します。
  #
  # build 済みかの確認を行いません。
  #
  # ```
  # n = 3
  # graph = BinaryLifting.new(n)
  # graph.add_edge(0, 1, 1)
  # graph.add_edge(1, 2, 10)
  # graph.add_edge(2, 0, 100)
  #
  # graph.where!(start: 0, times: 5) # => 2
  # graph.where!(start: 1, times: 5) # => 0
  # ```
  def where!(start : Int, times : Int)
    query!(start, times)[1]
  end

  # 頂点 start から times 回移動する経路中の重みの総和を返します。
  #
  # ```
  # n = 3
  # graph = BinaryLifting.new(n)
  # graph.add_edge(0, 1, 1)
  # graph.add_edge(1, 2, 10)
  # graph.add_edge(2, 0, 100)
  #
  # graph.weight_sum(start: 0, times: 5) # => 122
  # graph.weight_sum(start: 1, times: 5) # => 221
  # ```
  def weight_sum(start : Int, times : Int)
    build if @should_build
    query(start, times)[0]
  end

  # 頂点 start から times 回移動する経路中の重みの総和を返します。
  #
  # build 済みかの確認を行いません。
  #
  # ```
  # n = 3
  # graph = BinaryLifting.new(n)
  # graph.add_edge(0, 1, 1)
  # graph.add_edge(1, 2, 10)
  # graph.add_edge(2, 0, 100)
  #
  # graph.weight_sum!(start: 0, times: 5) # => 122
  # graph.weight_sum!(start: 1, times: 5) # => 221
  # ```
  def weight_sum!(start : Int, times : Int)
    query!(start, times)[0]
  end

  # 頂点 start から times 回移動する経路中の重みの総和と場所を返します。
  #
  # ```
  # n = 3
  # graph = BinaryLifting.new(n)
  # graph.add_edge(0, 1, 1)
  # graph.add_edge(1, 2, 10)
  # graph.add_edge(2, 0, 100)
  #
  # graph.query(start: 0, times: 5) # => {2, 122}
  # graph.query(start: 1, times: 5) # => {0, 221}
  # ```
  def query(start : Int, times : Int)
    build if @should_build
    query!(start, times)
  end

  # 頂点 start から times 回移動する経路中の重みの総和と場所を返します。
  #
  # build 済みかの確認を行いません。
  #
  # ```
  # n = 3
  # graph = BinaryLifting.new(n)
  # graph.add_edge(0, 1, 1)
  # graph.add_edge(1, 2, 10)
  # graph.add_edge(2, 0, 100)
  #
  # graph.query!(start: 0, times: 5) # => {2, 122}
  # graph.query!(start: 1, times: 5) # => {0, 221}
  # ```
  def query!(start : Int, times : Int)
    acc = T.zero
    (@log - 1).downto(0).each do |k|
      if times.bit(k) == 1
        acc += @table[start][k][1]
        start = @table[start][k][0]
      end
      break if start == -1
    end
    {acc, start}
  end

  [AlwaysInline]
  def impl_log2(x : Int) : Int32
    Int32.new(sizeof(typeof(x)) * 8 - x.leading_zeros_count)
  end
end
