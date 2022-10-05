# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
def min(x : Int64, y : Int64) : Int64; x < y ? x : y end
def max(x : Int64, y : Int64) : Int64; x > y ? x : y end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
BLACK = 0
WHITE = 1
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
graph = Array.new(n){ Array(Int64).new }
(n - 1).times do
  x, y = ints -1
  graph[x] << y
  graph[y] << x
end

cache = Array.new(n){ Array(Mint?).new(2){ nil } }
dp = uninitialized Proc(Int64, Int64, Int32, Mint)
dp = ->(subroot : Int64, parent : Int64, color : Int32) do
  return cache[subroot][color].not_nil! if cache[subroot][color]
  cache[subroot][color] = graph[subroot].reject{ |v| v == parent }.reduce(1.to_m) do |acc, child|
    if color == BLACK
      acc * dp.call(child, subroot, WHITE)
    else
      acc * (dp.call(child, subroot, BLACK) + dp.call(child, subroot, WHITE))
    end
  end
  return cache[subroot][color].not_nil!
end

puts dp.call(0_i64, -1_i64, BLACK) + dp.call(0_i64, -1_i64, WHITE)



macro static_modint(modint, mod)
  struct {{ modint }}
    getter val : Int64

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

    def inv : self
      {{ modint }}.new modinv(@val, {{ mod }})
    end

    def pow(n : Int64) : self
      {{ modint }}.new modpow(@val, n, {{ mod }})
    end

    def self.zero : self
      {{ modint }}.new 0_i64
    end

    def to_i; @val.to_i end
    def to_i32; @val.to_i32 end
    def to_i64; @val.to_i64 end
    def to_s(io : IO); io << @val end
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
static_modint(Mint1000000007, 1_000_000_007_i64)
# static_modint(Mint998244353, 998_244_353_i64)
alias Mint = Mint1000000007