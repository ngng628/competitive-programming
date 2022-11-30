# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, q = ints

dsu = DisjointSet.new(n + q)

# ball -> box
where = Array.new(n + q){ |i| i.to_i64 }

# box -> ball (leader)
leaders = Array(Int64?).new(n + q){ |i| i.to_i64 }

k = n - 1

q.times do
  r = ints
  t = r[0]
  x = r[1] - 1
  y = (r[2]? || 0_i64) - 1

  case t
  when 1
    bx = leaders[x]
    by = leaders[y]
    next if bx.nil? && by.nil?
    if !bx.nil? && !by.nil?
      dsu.unite(bx, by)
    end
    l = dsu.leader((bx || by).not_nil!)
    where[l] = x
    leaders[x] = l
    leaders[y] = nil
  when 2
    bx = leaders[x]
    unless bx.nil?
      dsu.unite(bx, k + 1)
    end
    l = dsu.leader(k + 1)
    k += 1
    where[l] = x
    leaders[x] = l
    leaders[k + 1] = nil
  when 3
    l = dsu.leader(x)
    puts where[l] + 1
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