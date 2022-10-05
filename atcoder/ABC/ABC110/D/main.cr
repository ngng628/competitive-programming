# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int64, b : Int64) : Int64; a < b ? a : b end
def max(a : Int64, b : Int64) : Int64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
MAX = 2_i64 * 10**5
P = Prime.new MAX + 1
combi = Combination.mod1000000007(MAX + 1)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
if m == 1
  puts 1
  exit
end
factors = P.factor(m)
ans = factors.reduce(1.to_m) do |prod, (_prime, a)|
  prod * combi.calc(n + a - 1, a)
end
puts ans





class Prime
  getter capacity : Int64
  @table : Array(Bool)
  @osak : Array(Int64)
  @list : Array(Int64)
  getter pi : Array(Int64)  # n 以下の 素数の個数

  def initialize
    @capacity = 0
    @table = Array.newpush
    @osak = Array.new
    @list = Array.new
    @pi = Array.new
  end

  def initialize(@capacity : Int64)
    @table = Array.new(@capacity + 1, true)
    @osak = (0_i64..@capacity).to_a
    @pi = Array.new(@capacity + 1, 0_i64)
    if @capacity >= 0; @table[0] = false end
    if @capacity >= 1; @table[1] = false end

    i = 1_i64
    while i**2 <= @capacity
      i += 1
      @pi[i] = @pi[i - 1]
      next unless @table[i]
      k = 2_i64*i
      while k <= @capacity
        @table[k] = false
        @osak[k] = i
        k += i
      end
      @pi[i] += 1
    end

    @list = Array(Int64).new
    (1..@capacity).each do |i|
      @pi[i] = @pi[i - 1] + (@table[i] ? 1_i64 : 0_i64)
      if @table[i]
        @list.push(i.to_i64)
      end
    end
  end

  # 素数であれば `true` を返します。
  #
  # 計算量 : `O(1)` if n <= capacity else `O(sqrt(N))`
  #
  # ```
  # PRIME.is? 0 # => false
  # PRIME.is? 1 # => false
  # PRIME.is? 2 # => true
  # ```
  def is?(n : Int) : Bool
    if n <= @capacity
      @table[n]
    elsif n <= 4
      n == 2 || n == 3
    elsif n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)
      false
    else
      i = 5
      ok = true
      while i**2 <= n
        if n % i == 0 || n % (i + 2) == 0
          ok = false
          break
        end
        i += 6
      end
      ok
    end
  end

  # 素因数分解の結果をハッシュで返します。
  # `p**a` の `p` がキーで `a` が値です
  #
  # 計算量 : `O(log(N))` if n <= capacity else `O(sqrt(N))`
  #
  # ```
  # PRIME.factor? 24 # => { 2 => 3, 3 => 1 }
  # ```
  def factor(n : Int) : Hash(Int64, Int64)
    return { 1_i64 => 1_i64 } if n == 1
    return factor_fast_impl(n) if n <= @capacity
    res = Hash(Int64, Int64).new(0_i64)
    i = 2_i64
    while i * i <= n
      while n % i == 0
        res[i] += 1
        n //= i
      end
      i += 1
    end
    res[n] = 1 if n != 1
    res
  end

  private def factor_fast_impl(n : Int) : Hash(Int64, Int64)
    res = Hash(Int64, Int64).new(0_i64)
    until n == 1
      prime = @osak[n]
      res[prime] += 1
      n //= prime
    end
    res
  end

  # *enumerable* の値が互いに素であれば `true` を返します。
  #
  # 計算量 : `O(ary.size * log(ary.max))`
  #
  # ```
  # PRIME.to? [2, 3, 5] # => true
  # PRIME.to? [2, 3, 4] # => false
  # ```
  def to?(elems : Enumerable(Int64)) : Bool
    s = Set(Int64).new
    elems.each do |n|
      until n == 1
        prime = @osak[n]
        return false if s.includes? prime
        s << prime
        while n % prime == 0
          n //= prime
        end
      end
    end
    true
  end
end

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

    def inv : {{ modint }}
      {{ modint }}.new modinv(@val, {{ mod }})
    end

    def pow(n : Int64) : {{ modint }}
      {{ modint }}.new modpow(@val, n, {{ mod }})
    end

    def to_i; @val.to_i end
    def to_i32; @val.to_i32 end
    def to_i64; @val.to_i64 end
    def to_s(io : IO); io << @val end
  end

  struct Int
    def to_m
      {{ modint }}.new self
    end

    def +(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} + other.val end
    def -(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} - other.val end
    def *(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} * other.val end
    def /(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} * other.inv.val end
    def //(other : {{ modint }}) : {{ modint }}; self.to_i64 / other end
  end
end
static_modint(Mint1000000007, 1_000_000_007_i64)
alias Mint = Mint1000000007