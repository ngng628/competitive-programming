# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
ab = (1..n).map { ints }

dp = Array.new(n + 1) { Array.new(2) { 0.to_m } }
# dp[0][0] = 1.to_m
# dp[0][1] = 1.to_m
(0...n).each do |i|
  if i == 0
    dp[i + 1][0] = 1.to_m
    dp[i + 1][1] = 1.to_m
  else
    # 表
    dp[i + 1][0] += dp[i][0] if ab[i][0] != ab[i - 1][0]
    dp[i + 1][0] += dp[i][1] if ab[i][0] != ab[i - 1][1]
  
    # 裏
    dp[i + 1][1] += dp[i][0] if ab[i][1] != ab[i - 1][0]
    dp[i + 1][1] += dp[i][1] if ab[i][1] != ab[i - 1][1]
  end
end

puts dp[n].sum













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
