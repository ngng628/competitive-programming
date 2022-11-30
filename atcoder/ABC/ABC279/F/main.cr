# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, q = ints

hash = Hash(Int64, Set(Int64)).new
acc = 0_i64

where = Array.new(n + q){ |i| i.to_i64 }
box_leader = Array.new(n){ |i| i.to_i64 }
ut = DisjointSet.new(n + q)
cur = n - 1

q.times do
  input = str.split
  t = input[0].to_i64
  x = input[1].to_i64 - 1
  y = (input[2]? || 0).to_i64 - 1

  case t
  when 1
    puts "箱 #{x} の中身を箱 #{y} に移します。"
    u = box_leader[x]
    v = box_leader[y]
    ut.unite(u, v)
    where[ut.leader(x)] = x
    box_leader[x] = box_leader[y] = ut.leader(x)
  when 2
    puts "箱 #{x} に #{cur} を入れます。"
    cur += 1
    ut.unite(box_leader[x], cur)
    where[ut.leader(x)] = x
    box_leader[x] = ut.leader(x)
  when 3
    puts "ボール #{x} はどこにありますか？"
    l = ut.leader(x)
    puts where[x]
  end
  puts "─" * 40
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