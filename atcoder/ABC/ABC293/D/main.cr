# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
ut = DisjointSet.new(2 * n)
graph = Array.new(2 * n) { [] of Int64 }
n.times do |i|
  ut.unite(2*i, 2*i + 1)
  graph[2*i] << 2*i + 1
  graph[2*i + 1] << 2*i
end

m.times do |i|
  a2, b, c2, d = str.split
  a = a2.to_i64 - 1
  c = c2.to_i64 - 1

  u = if b == 'R'
    2*a
  else
    2*a + 1
  end
  v = if d == 'R'
    2*c
  else
    2*c + 1
  end

  ut.unite(u, v)
  graph[u] << v
  graph[v] << u
end

ans_x, ans_y = 0_i64, 0_i64
ut.groups.each do |group|
  pp! group
  graph2 = Array.new(group.size) { [] of Int64 }
  hash = Hash(Int64, Int64).new
  group.each do |v|
    hash[v] = hash.size
  end

  group.each do |from|
    graph[from].each do |to|
      graph2[hash[from]] << hash[to]
    end
  end

  closed = [false] * group.size
  cycle = false
  dfs = uninitialized Int64, Int64 -> Nil
  dfs = ->(from : Int64, pre : Int64) do
    graph2[from].each do |to|
      if closed[to] && to != pre
        cycle = true
      end
      next if closed[to]
      closed[to] = true
      dfs.call(to, )
    end
    nil
  end
  closed[hash[group[0]]] = true
  dfs.call(hash[group[0]])

  if cycle
    ans_x += 1
  else
    ans_y += 1
  end
end

puts "#{ans_x} #{ans_y}"




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
