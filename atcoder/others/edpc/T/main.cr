# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
s = ("_" + str).chars

ans = (1..n).reduce(Array.new(n + 1){ |i| i == 0 ? 1.to_m : 0.to_m }) do |dp, i|
  csum = StaticRangeSum.new(dp)
  dp2 = Array.new(n + 1){ 0.to_m }
  (1..i).each do |j|
    if i == 1
      dp2[j] = 1.to_m
    else      
      if s[i - 1] == '<'
        dp2[j] += csum[j...]
      else
        dp2[j] += csum[...j]
      end
    end
  end
  dp2
end.sum

puts ans

class StaticRangeSum(T)
  getter size : Int64
  getter csum : Array(T)

  def initialize(array : Array(T))
    @size = array.size.to_i64
    @csum = Array.new(@size + 1, T.zero)
    @size.times { |i| @csum[i + 1] = @csum[i] + array[i] }
  end

  def get(left, right) : T
    raise IndexError.new("`left` must be less than or equal to `right` (#{left}, #{right})") unless left <= right
    @csum[right] - @csum[left]
  end

  def get(range : Range(Int?, Int?)) : T
    left = (range.begin || 0)
    right = (range.end || @size) + (range.exclusive? ? 0 : 1)
    get(left, right)
  end
  
  def get?(left, right) : T?
    return nil unless left <= right
    get(left, right)
  end

  def get?(range : Range(Int?, Int?)) : T?
    left = (range.begin || 0)
    right = (range.end || @size) + (range.exclusive? ? 0 : 1)
    get?(left, right)
  end

  def get!(left, right) : T
    @csum[right] - @csum[left]
  end

  def get!(range : Range(Int?, Int?)) : T
    left = (range.begin || 0)
    right = (range.end || @size) + (range.exclusive? ? 0 : 1)
    get!(left, right)
  end

  def [](left, right) : T; get(left, right) end
  def [](range : Range(Int?, Int?)) : T; get(range) end
  def []?(left, right) : T?; get?(left, right) end
  def []?(range : Range(Int?, Int?)) : T?; get?(range) end
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
static_modint(ModInt1000000007, 1_000_000_007_i64)
# static_modint(ModInt998244353, 998_244_353_i64)
alias ModInt = ModInt1000000007