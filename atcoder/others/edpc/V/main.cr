  # ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
macro static_modint(modint, mod)
  struct {{ modint }}  
    include Comparable({{ modint }})

    MOD = {{ mod }}
    getter val : Int64

    delegate popcount, to: val
    delegate trailing_zeros_count, to: val

    def initialize
      @val = 0
    end

    def initialize(@val : Int64)
      @val %= {{ mod }}
    end

    def + : self; self end
    def - : self; {{ modint }}.new -@val end

    def +(other : self) : self; {{ modint }}.new @val + other.val end
    def -(other : self) : self; {{ modint }}.new @val - other.val end
    def *(other : self) : self; {{ modint }}.new @val * other.val end
    def /(other : self) : self; {{ modint }}.new @val * other.inv.val end
    def //(other : self) : self; self / other end

    def +(other : Int) : self; {{ modint }}.new @val + other end
    def -(other : Int) : self; {{ modint }}.new @val - other end
    def *(other : Int) : self; {{ modint }}.new @val * other end
    def **(other : Int) : self; self.pow(other.to_i64) end
    def /(other : Int) : self; {{ modint }}.new @val * modinv(other.to_i64, {{ mod }}) end
    def //(other : Int) : self; self / other end

    def <=>(other : self) : Int32; @val <=> other.val end
    
    def inv : self
      {{ modint }}.new modinv(@val, {{ mod }})
    end

    def pow(n : Int64) : self
      {{ modint }}.new modpow(@val, n, {{ mod }})
    end

    def abs : self
      self
    end

    def zero? : Bool
      @val == 0_i64
    end

    def self.zero : self
      {{ modint }}.new 0_i64
    end

    def clone
      {{ modint }}.new @val
    end

    def to_i; @val.to_i end
    def to_i32; @val.to_i32 end
    def to_i64; @val.to_i64 end
    def to_s(io : IO); io << @val end
    def inspect(io : IO); to_s(io) end
  end

  struct Int
    def to_m
      {{ modint }}.new self.to_i64
    end

    def +(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} + other.val end
    def -(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} - other.val end
    def *(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} * other.val end
    def /(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} * other.inv.val end
    def //(other : {{ modint }}) : {{ modint }}; self.to_i64 / other end
  end
end
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

alias Monoid = Int64

n, m = ints

f = ->(x : Monoid, v : Int64){ (x + 1) % m }
merge = ->(x : Monoid, y : Monoid){ x * y % m }
e = ->(){ 1_i64 }
g = ->(c : Monoid, now : Int64){ c }

tree = ReRootingTree(Monoid).new(n, f, merge, e, g)
(n - 1).times do
  x, y = ints -1
  tree.add_branch(x, y)
end

tree.grow

n.times do |v|
  puts tree.harvest(v) % m
end


class ReRootingTree(T)
  @n : Int64
  getter graph : Array(Array(Int64))
  @dp : Array(Array(T))
  @ans : Array(T)

  @merge : T, Int64 -> T
  @e : -> T
  @g : T, Int64 -> T

  def initialize(@n : Int64, @f : T, T -> T, @merge : T, T -> T, @e : -> T, @g : T, Int64 -> T)
    @graph = Array.new(@n){ Array(Int64).new }
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