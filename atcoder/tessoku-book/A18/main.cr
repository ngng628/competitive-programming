# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, s = ints
a = ints
sss = SubsetSumSolver.zeroone(a, capacity: s)
puts sss.configurable?(s) ? "Yes" : "No"

class SubsetSumSolver
  enum ProblemType
    ZeroOne
    Limited
    Unlimited
  end

  @type : ProblemType
  @seq : Enumerable(Int32)
  @capacity : Int32
  @mod_old : Int64?
  getter exist : Array(Bool)
  getter ways : Array(Int64)

  # 0-1 部分和問題を解くためのソルバを生成します。
  #
  # ```
  # ss = SubsetSumSolver.zeroone([1, 1, 2, 3, 4], capacity: 30)
  # ```
  def self.zeroone(seq : Enumerable(Int), capacity : Int)
    new ProblemType::ZeroOne, seq.map(&.to_i32), capacity
  end

  # 個数制限付き部分和問題を解くためのソルバを生成します。
  #
  # ```
  # ss = SubsetSumSolver.limited([1, 2, 4], [{0, 1}, {3, 5}, {2, 10}], capacity: 30)
  # ```
  def self.limited(seq : Enumerable(Int32), lim : Enumerable(Int32), capacity : Int)
    raise NotImplementedError.new("TODO")
    new ProblemType::Limited, seq.map(&.to_i32), capacity
  end

  # 個数制限なし部分和問題を解くためのソルバを生成します。
  #
  # ```
  # ss = SubsetSumSolver.unlimited([1, 1, 2, 3, 4], capacity: 30)
  # ```
  def self.unlimited(seq : Enumerable(Int32), capacity : Int)
    new ProblemType::Unlimited, seq.map(&.to_i32), capacity
  end

  def initialize(@type : ProblemType, @seq : Enumerable(Int32), capacity : Int)
    @capacity = capacity.to_i32
    @exist = Array(Bool).new
    @ways = Array(Int64).new
    @mod_old = nil
  end

  # 値 x が構成可能なら `true` を返します。
  #
  # ```
  # ss = SubsetSumSolver.zeroone([1, 1, 2, 3, 4], capacity: 30)
  # ss.configurable?(0) # => true
  # ss.configurable?(2) # => true
  # ss.configurable?(30) # => false
  # ```
  def configurable?(x : Int)
    unless @exist.empty?
      return @exist[x]
    end

    case @type
    when ProblemType::ZeroOne
      @exist = Array.new(@capacity + 1){ |i| i == 0 }
      @seq.each_with_index do |ai, i|
        (ai..@capacity).reverse_each do |j|
          @exist[j] |= @exist[j - ai]
        end
      end
    when ProblemType::Limited
    when ProblemType::Unlimited
      @exist = Array.new(@capacity + 1){ |i| i == 0 }
      @seq.each_with_index do |ai, i|
        (ai..@capacity).each do |j|
          @exist[j] |= @exist[j - ai]
        end
      end
    end

    @exist[x]
  end

  # 値 x の構成方法が何通りあるか返します。
  #
  # `mod` を指定すると `mod` で割ったあまりを返します。
  #
  # ```
  # ss = SubsetSumSolver.zeroone([1, 1, 2, 3, 4], capacity: 30)
  # ss.n_ways?(0, 998244353) # => 1
  # ss.n_ways?(2, 998244353) # => 2
  # ss.n_ways?(30, 998244353) # => 0
  # ```
  def n_ways(x : Int, mod : Int64 = nil)
    if !@ways.empty? && mod == old_mod
      return @ways[x]
    end

    case @type
    when ProblemType::ZeroOne
      @ways = Array.new(@capacity + 1){ |i| i == 0 ? 1_i64 : 0_i64 }
      @seq.each_with_index do |ai, i|
        (ai..@capacity).reverse_each do |j|
          @ways[j] += @ways[j - ai]
          @ways[j] %= mod.not_nil! unless mod.nil?
        end
      end
    when ProblemType::Limited
    when ProblemType::Unlimited
      @ways = Array.new(@capacity + 1){ |i| i == 0 ? 1_i64 : 0_i64 }
      @seq.each_with_index do |ai, i|
        (ai..@capacity).each do |j|
          @ways[j] += @ways[j - ai]
          @ways[j] %= mod.not_nil! unless mod.nil?
        end
      end
    end

    old_mod = mod

    @ways[x]
  end
end