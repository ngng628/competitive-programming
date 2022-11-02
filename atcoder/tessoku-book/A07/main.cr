# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

d = int
n = int
imos = Imos.new(d)
n.times do
  l, r = ints
  imos.add(l..r, 1_i64)
end

puts imos[1..d].join("\n")


class Imos
  include Enumerable(Int64)

  getter capacity : Int64
  @shouldUpdate = true
  @memo : Array(Int64)
  @csum : Array(Int64)

  def initialize(@capacity, val : Int64 = 0_i64)
    @memo = Array(Int64).new(@capacity + 2){ val }
    @csum = Array.new(@capacity + 1){ 0_i64 }
  end

  # left 以上 right 未満の範囲に val を足します。
  def add(left, right, val = 1_i64) : Nil
    raise IndexError.new("`left` must be less than or equal to `right` (#{left}, #{right})") unless left <= right
    @shouldUpdate = true
    @memo[left] += val
    @memo[right] -= val
  end

  # range の範囲に val を足します。
  def add(range : Range(Int?, Int?), val = 1_i64) : Nil
    left = (range.begin || 0)
    right = (range.end || @capacity + 1) + (range.exclusive? ? 0 : 1)
    add(left, right)
  end

  # index の位置の値を返します。
  def get(index) : Int64
    cumsum[index]
  end

  # index の位置の値を返します。
  def get?(index) : Int64
    cumsum[index]?
  end

  # いもす法の累積和を取った後の値を返します。
  def cumsum : Array(Int64)
    update if @shouldUpdate
    @csum.dup
  end

  def each
    update if @shouldUpdate
    cumsum.each{ |v| yield v }
  end

  # いもす法の累積和を更新します。
  def update : Nil
    @csum = @memo.dup
    (1..@capacity+1).each{ |i| @csum[i] += @csum[i - 1] }
    @shouldUpdate = false
  end

  def to_s(io : IO) : Nil
    io << cumsum.to_s
  end

  def inspect(io : IO) : Nil
    to_s(io)
  end

  def [](index) : Int64
    get(index)
  end

  def []?(index) : Int64
    get?(index)
  end

  def [](range : Range(Int?, Int?)) : Array(Int64)
    left = (range.begin || 0)
    right = (range.end || @capacity + 1) + (range.exclusive? ? 0 : 1)
    cumsum[left...right]
  end

  def []?(range : Range(Int?, Int?)) : Array(Int64)
    left = (range.begin || 0)
    right = (range.end || @capacity + 1) + (range.exclusive? ? 0 : 1)
    cumsum[left...right]?
  end
end