# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

k = int

factors = PRIME.factor(k) # => k の素因数分解

ans = if factors.all?{ |pi, ai| ai * pi <= 10**6 }
  cnt = factors.keys.reduce({} of Int64 => Int64){ |acc, pi| acc[pi] = 0_i64; acc }
  (1_i64..).find do |x|
    PRIME.factor(x).each do |pi, ai|
      next unless factors.has_key?(pi)
      cnt[pi] = Math.min(factors[pi], cnt[pi] + ai)
    end
    cnt == factors
  end
else
  factors.max_of{ |pi, ai| ai * pi }
end

puts ans





class Prime
  getter capacity : Int64
  @table : Array(Bool)
  @osak : Array(Int64)
  @list : Array(Int64)
  getter pi : Array(Int64)  # n 以下の 素数の個数

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

PRIME = Prime.new 10_i64**6 + 10
struct Int
  def prime?
    PRIME.is? self
  end

  def factor
    PRIME.factor(self)
  end
end

struct Int
  def divisors
    lo = Array(Int64).new
    hi = Array(Int64).new
    i = 1_i64
    while i**2 <= self
      if self % i == 0
        j = self // i
        lo << i
        if i != j
          hi << j
        end
      end
      i += 1
    end
    lo + hi
  end
end