# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, r = ints
binom = Combination.mod1000000007(100000)
puts binom.calc(n, r)




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