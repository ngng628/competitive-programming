# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
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

n, m, q = ints
graph = Graph.new(n){ Edges.new }
ut = DisjointSet.new(n)
m.times do
  a, b, c = ints
  a -= 1
  b -= 1
  graph[a] << Edge.new(b, -c)
  graph[b] << Edge.new(a, c)
  ut.unite(a, b)
end

dist = [OO] * n
infs = [false] * n
ut.groups.map{ |g| ut.leader(g[0]) }.each do |s|
  que = Deque(Int64).new([ s ])
  dist[s] = 0
  until que.empty?
    from = que.shift
    graph[from].each do |(to, w)|
      if dist[to] == OO
        dist[to] = dist[from] + w
        que << to
      elsif dist[to] != dist[from] + w
        infs[s] = true
      end
    end
  end
end

q.times do
  x, y = ints -1
  if !ut.equiv?(x, y)
    puts "nan"
  else
    l = ut.leader(x)
    if infs[l]
      puts "inf"
    else
      puts dist[x] - dist[y]
    end
  end
end




class DisjointSet
  @n : Int64
  @parent_or_size : Array(Int64)

  def initialize
    @n = 0
    @parent_or_size = Array(Int64).new
  end

  def initialize(@n : Int64)
    @parent_or_size = Array(Int64).new(n, -1_i64)
  end

  def unite(a : Int64, b : Int64) : Int64
    x = leader(a)
    y = leader(b)
    return x.to_i64 if x == y
    if -@parent_or_size[x] < -@parent_or_size[y]
      x, y = y, x
    end
    @parent_or_size[x] += @parent_or_size[y]
    @parent_or_size[y] = x
    x.to_i64
  end

  def equiv?(a : Int64, b : Int64) : Bool
    leader(a) == leader(b)
  end

  def leader(a : Int64) : Int64
    return a.to_i64 if @parent_or_size[a] < 0
    @parent_or_size[a] = leader(@parent_or_size[a])
    @parent_or_size[a].to_i64
  end

  def size(a : Int64) : Int64
    -@parent_or_size[leader(a)].to_i64
  end

  def groups : Array(Array(Int64)) | Nil
    leader_buf = Array(Int64).new(@n, 0_i64)
    group_size = Array(Int64).new(@n, 0_i64)
    @n.times do |i|
      leader_buf[i] = leader(i)
      group_size[leader_buf[i]] += 1
    end
    res = Array.new(@n){ Array(Int64).new() }
    @n.times do |i|
      res[leader_buf[i]] << i.to_i64
    end
    res.delete([] of Int64)
    res
  end
end