# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
graph = Array.new(n) { [] of Int64 }
ut = DisjointSet.new(n)
m.times do
  u, v = ints -1
  graph[u] << v
  graph[v] << u
  ut.unite(u, v)
end

ans = ut.groups.all? { |group|
  cnt = 0_i64
  group.each do |v|
    graph[v].each do |u|
      cnt += 1
    end
  end
  cnt == group.size * 2
}

puts ans ? "Yes" : "No"


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
