# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
lrs = (1..n).map do
  x, y = ints
  (Fraction.new(y - 1, x)...Fraction.new(y, x - 1))
end

lrs.sort_by! do |range|
  range.end
end

ans = 0
last = -1.to_frac
lrs.each do |range|
  next if last > range.begin
  ans += 1
  last = range.end
end

puts ans



struct Fraction
  include Comparable(Fraction)

  getter num : Int64
  getter den : Int64

  def self.zero
    new
  end

  def self.infinity
    new 1, 0
  end

  def initialize
    @num = 0_i64
    @den = 1_i64
  end

  def initialize(n : Int)
    @num = n.to_i64
    @den = 1_i64
  end

  def initialize(n : Int, d : Int)
    @num = n.to_i64
    @den = d.to_i64
    reduce
  end

  def initialize(s : String)
    pos = s.index(".")
    if pos.nil?
      @num = s.to_i64
      @den = 1
    else
      @den = 1_i64
      ten = 10_i64

      m = s.size - 1 - pos
      until m == 0
        @den *= ten if m.bit(0) == 1
        ten *= ten
        m >>= 1
      end

      @num = 0
      s.chars.each do |c|
        @num = 10_i64 * @num + c.to_i if c != '.'
      end
    end
    reduce
  end

  def infinity?
    @den == 0
  end

  def inv : Fraction
    Fraction.new(@den, @num)
  end

  def abs : Fraction
    Fraction.new(@num.abs, @den.abs)
  end

  def num=(n : Int)
    @num = n.to_i64
    reduce
  end

  def den=(d : Int)
    @den = d.to_i64
    reduce
  end

  def +(other : Fraction)
    l = infinity? || other.infinity? ? 1_i64 : @den.lcm(other.den)
    n = @num * (l // @den) + other.num * (l // other.den)
    Fraction.new(n, l)
  end

  def -(other : Fraction)
    l = infinity? || other.infinity? ? 1_i64 : @den.lcm(other.den)
    n = @num * (l // @den) - other.num * (l // other.den)
    Fraction.new(n, l)
  end

  def *(other : Fraction)
    g1 = @den.gcd(other.num)
    g2 = @num.gcd(other.den)
    n = (@num // g2) * (other.num // g1)
    d = (@den // g1) * (other.den // g2)
    Fraction.new(n, d)
  end

  def /(other : Fraction)
    g1 = @den.gcd(other.num)
    g2 = @num.gcd(other.den)
    n = (@num // g2) * (other.den // g1)
    d = (@den // g1) * (other.num // g2)
    Fraction.new(n, d)
  end

  def //(other : Fraction)
    self / other
  end

  def +(other : Int)
    Fraction.new(@num + @den * other, @den)
  end

  def -(other : Int)
    Fraction.new(@num - @den * other, @den)
  end

  def *(other : Int)
    g = infinity? ? 1_i64 : @den.gcd(other)
    Fraction.new(@num * (other // g), @den // g)
  end

  def /(other : Int)
    g = infinity? ? 1_i64 : @num.gcd(other)
    Fraction.new(@num // g, @den * (other // g))
  end

  def //(other : Int)
    self / ther
  end

  def //(other : Fraction)
    self // other
  end

  def +
    self
  end

  def -
    Fraction.new(-@num, @den)
  end

  # Note: オーバーフローの可能性があります。
  def <=>(other : Fraction)
    @num * other.den <=> @den * other.num
  end

  def to_f
    @num / @den
  end

  def to_i
    @num // @den
  end

  def to_i32
    (@num // @den).to_i32
  end

  def to_i64
    (@num // @den).to_i32
  end

  def to_s(io : IO)
    io << @num << '/' << @den
  end

  def inspect(io : IO)
    to_s(io)
  end

  # 約分をします。
  #
  # 分数が負の場合は分子が負になるようにします。
  #
  # @num != 0 かつ @den != 0 かつ分母分子が互いに素でないとき `true` を返します。
  def reduce : Bool
    if @den < 0
      @num *= -1
      @den *= -1
    end

    if @num == 0
      @den = 1
      false
    elsif @den == 0
      @num = 1
      false
    else
      g = @num.gcd(@den)
      @num //= g
      @den //= g
      g != 1
    end
  end
end

struct Int
  def to_frac
    Fraction.new(self)
  end
end