# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
graph = Array.new(n){ Array(Int64).new }
n.times{ u, v = ints -1; graph[u] << v; graph[v] << u }

closed = Array.new(n){ false }
root = ->() do
  n.times do |i|
    next if closed[i]
    stack = Deque({Int64, Int64}).new
    stack << {i, -1_i64}
    until stack.empty?
      v, par = stack.pop
      graph[v].each do |c|
        next if c == par
        return c if closed[c]
        closed[c] = true
        stack << {c, v}
      end
    end
    return nil
  end
end.call.not_nil!

closed = Array.new(n){ false }
dfs = uninitialized Proc(Int64, Int64, Deque(Int64), Bool)
dfs = ->(from : Int64, par : Int64, stack : Deque(Int64)) do
  stack << from
  res = false
  graph[from].each do |to|
    next if to == par

    if closed[to]
      return true
    end
    closed[to] = true
    res |= dfs.call(to, from, stack)
  end
  stack.pop unless res
  return res
end

stack = Deque(Int64).new
dfs.call(root, -1_i64, stack)
group = Set.new(stack)

ut = DisjointSet.new(n)
n.times do |u|
  graph[u].each do |v|
    next if group.includes?(u) && group.includes?(v)
    ut.unite(u, v)
  end
end

q = int
q.times do
  x, y = ints -1
  ans = ut.equiv?(x, y)
  puts ans ? "Yes" : "No"
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