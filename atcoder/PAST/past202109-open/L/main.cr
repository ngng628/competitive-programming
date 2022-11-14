# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints.compress.map{ |v| v + 1 }

dp1 = DynamicRangeSum.new(a.max + 1, 0.to_m)
a.each_with_index do |ai, i|
  dp1[ai] = dp1[ai] + dp1[...ai]
end

dp2 = DynamicRangeSum.new(a.max + 1, 0.to_m)
a.each_with_index do |ai, i|
  dp2[ai] = dp2[ai] + dp2[ai + 1...]
end


puts dp1[...] + dp2[...]


class DynamicRangeSum(T)
  getter size : Int32
  @data : Array(T)

  def initialize(n : Int)
    @data = Array(T).new(n){ T.zero }
    @size = @data.size
  end

  def initialize(n : Int, val : T)
    @data = Array(T).new(n){ val }
    @size = @data.size
  end

  def initialize(elems : Enumerable(T))
    @size = elems.size.to_i64
    @data = Array(T).new(@size, T.zero)
    elems.each_with_index{ |x, i| add(i, x) }
  end

  def get(left : Int, right : Int) : T
    raise IndexError.new("`left` and `right` must be 0 <= left <= right <= self.size (#{left}, #{right})") unless 0 <= left && left <= right && right <= @size
    sum(right) - sum(left)
  end

  def get?(left : Int, right : Int) : T?
    return nil unless 0 <= left && left <= right && right <= @size
    get(left, right)
  end

  def get(i : Int) : T
    get(i, i + 1)
  end

  def get?(i : Int) : T?
    get?(i, i + 1)
  end

  {% begin %}
    {% for int1 in Int.union_types + [Nil] %}
      {% for int2 in Int.union_types + [Nil] %}
        def get(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get(left, right)
        end

        def get?(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get?(left, right)
        end

        def [](range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get(left, right)
        end

        def []?(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get?(left, right)
        end
      {% end %}
    {% end %}
  {% end %}

  def [](i : Int) : T; get(i, i + 1) end
  def []?(i : Int) : T?; get?(i, i + 1) end

  def [](l : Int, r : Int) : T; get(l, r) end
  def []?(l : Int, r : Int) : T?; get?(l, r) end

  def []=(i : Int, x : T) : T; add(i, x - get(i)) end

  def add(i : Int, x : T)
    i += 1
    while (i <= @size)
      @data[i - 1] += x
      i += i & -i
    end
    x
  end

  private def sum(r : Int) : T
    s = T.zero
    while r > 0
      s += @data[r - 1]
      r -= r & -r
    end
    s
  end
end

class Array(T)
  def compress
    b = clone.sort.uniq
    f, g = Hash(Int64, Int64).new, Hash(Int64, Int64).new
    map{ |s| b.bsearch_index{ |x| x >= s } || b.size }
  end

  def mapping
    b = clone.sort.uniq
    f, g = Hash(Int64, Int64).new, Hash(Int64, Int64).new
    each do |s|
      index = b.bsearch_index{ |x| x >= s } || b.size
      f[s] = index
      g[index] = s
    end
    {f, g}
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
static_modint(ModInt1000000007, 1_000_000_007_i64)
# static_modint(ModInt998244353, 998_244_353_i64)
alias ModInt = ModInt1000000007