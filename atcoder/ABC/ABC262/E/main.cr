# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

MOD = 998244353

n, m, k = ints
graph = Array.new(n){ Array(Int64).new }
m.times do
  u, v = ints -1
  graph[u] << v
  graph[v] << u
end

cnt = graph.map{ |edges| edges.size }
n_odds = cnt.count(&.odd?).to_i64

combi = Combination.mod998244353(n)
ans = (0_i64..n_odds).select(&.even?).sum do |i|
  ModInt.new (combi.calc(n_odds, i) * combi.calc(n - n_odds, k - i))
end
puts ans

class Combination
  @fact : Array(Int64)
  @finv : Array(Int64)
  @inv : Array(Int64)
  @mod : Int64

  def self.mod1000000007(max : Int64)
    new max, 1000000007_i64
  end

  def self.mod998244353(max : Int64)
    new max, 998244353_i64
  end

  def initialize(@max : Int64, @mod : Int64)
    @fact = Array.new(@max + 1, 0_i64)
    @finv = Array.new(@max + 1, 0_i64)
    @inv = Array.new(@max + 1, 0_i64)
    @fact[0] = @fact[1] = 1_i64
    @finv[0] = @finv[1] = 1_i64
    @inv[1] = 1_i64
    (2_i64..@max.to_i64).each do |i|
      @fact[i] = @fact[i - 1] * i % @mod
      @inv[i] = @mod - @inv[@mod % i] * (@mod // i) % @mod
      @finv[i] = @finv[i - 1] * @inv[i] % @mod
    end
  end

  def calc(n : Int64, r : Int64) : Int64
    if n < r
      0_i64
    elsif n < 0 || r < 0
      0_i64
    else
      @fact[n] * (@finv[r] * @finv[n - r] % @mod) % @mod
    end
  end
end

def modinv(a : Int64, mod : Int64) : Int64
  b = mod
  u = 1_i64
  v = 0_i64
  until b == 0
    t = a // b
    a -= t * b
    a, b = b, a
    u -= t * v
    u, v = v, u
  end
  u % mod
end

def modpow(a : Int64, n : Int64, mod : Int64) : Int64
  res = 1_i64
  until n == 0
    res = res * a % mod if n.odd?
    a = a * a % mod
    n >>= 1
  end
  res
end

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
# static_modint(ModInt1000000007, 1_000_000_007_i64)
static_modint(ModInt998244353, 998_244_353_i64)
alias ModInt = ModInt998244353