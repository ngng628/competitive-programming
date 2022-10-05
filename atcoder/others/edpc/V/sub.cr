  # ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

record Monoid, dist : Int64, n_childs : Int64
f = ->(dp_c : Monoid, c : Int64){ dp_c }
merge = ->(acc : Monoid, x : Monoid){ Monoid.new(acc.dist + x.dist, acc.n_childs + x.n_childs) }
e = ->(){ Monoid.new(0_i64, 0_i64) }
g = ->(acc : Monoid, v : Int64){ Monoid.new(acc.dist + acc.n_childs, acc.n_childs + 1) }

n = int
tree = ReRootingTree(Monoid).new(n, f, merge, e, g)
graph = Array.new(n){ Array(Int64).new }
(n - 1).times do
  x, y = ints -1
  tree.add_branch(x, y)
end

tree.grow

n.times do |v|
  puts tree.harvest(v).dist
end


class ReRootingTree(T)
  @n : Int64
  getter graph : Array(Array(Int64))
  @dp : Array(Array(T))
  @ans : Array(T)

  @f : T, Int64 -> T
  @merge : T, T -> T
  @e : -> T
  @g : T, Int64 -> T

  def initialize(@n : Int64, @f : T, Int64 -> T, @merge : T, T -> T, @e : -> T, @g : T, Int64 -> T)
    @graph = Array.new(@n){ Array(Int64).new }
    @dp = Array.new(@n){ Array(T).new }
    @ans = Array.new(@n){ @e.call }
  end

  def initialize(@graph : Array(Array(Int64)), @f : T, T -> T, @merge : T, T -> T, @e : -> T, @g : T, Int64 -> T)
    @n = @graph.size.to_i64
    @dp = Array.new(@n){ Array(T).new }
    @ans = Array.new(@n){ @e.call }
  end

  def add_branch(u : Int, v : Int)
    @graph[u] << v
    @graph[v] << u
  end

  def grow
    @dp = Array.new(@n){ |v| Array(T).new(@graph[v].size){ @e.call } }

    dfs(0_i64, -1_i64)
    bfs(0_i64, @e.call, -1_i64)

    @n.times do |i|
      @graph[i].each_with_index do |v, j|
        @ans[i] = @merge.call(@ans[i], @f.call(@dp[i][j], v))
      end
      @ans[i] = @g.call(@ans[i], i)
    end
  end

  def harvest(i : Int) : T
    @ans[i]
  end

  def harvest?(i : Int) : T?
    @ans[i]?
  end

  private def dfs(subroot : Int64, par : Int64) : T
    res = @e.call
    @graph[subroot].each_with_index do |child, i|
      next if child == par
      @dp[subroot][i] = dfs(child, subroot)
      res = @merge.call(res, @f.call(@dp[subroot][i], child))
    end
    @g.call(res, subroot)
  end

  private def bfs(subroot : Int64, dp_p : T, par : Int64)
    deg = @graph[subroot].size
    deg.times.each do |i|
      if @graph[subroot][i] == par
        @dp[subroot][i] = dp_p
        break
      end
    end

    dp_l = Array.new(deg + 1){ @e.call }
    dp_r = Array.new(deg + 1){ @e.call }
    deg.times{ |i| dp_l[i + 1] = @merge.call(dp_l[i], @f.call(@dp[subroot][i], @graph[subroot][i])) }
    (1..deg).reverse_each{ |i| dp_r[i - 1] = @merge.call(dp_r[i], @f.call(@dp[subroot][i - 1], @graph[subroot][i - 1])) }

    deg.times do |i|
      child = @graph[subroot][i]
      next if child == par
      val = @merge.call(dp_l[i], dp_r[i + 1])
      bfs(child, @g.call(val, subroot), subroot)
    end
  end
end