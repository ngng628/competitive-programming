# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
def min(x : Int64, y : Int64) : Int64; x < y ? x : y end
def max(x : Int64, y : Int64) : Int64; x > y ? x : y end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints
cumsum = StaticRangeSum.new(a)

cache = Array.new(n + 1){ Array(Int64?).new(n + 1){ nil }}
dp = uninitialized Proc(Int64, Int64, Int64)
dp = ->(left : Int64, right : Int64) do
  return cache[left][right].not_nil! if cache[left][right]
  return cache[left][right] = 0_i64 if right - left == 1

  cache[left][right] = (left + 1..right - 1).min_of do |i|
    dp.call(left, i) + dp.call(i, right) + cumsum[left...right]
  end

  cache[left][right].not_nil!
end

puts dp.call(0_i64, n)

class StaticRangeSum(T)
  getter size : Int64
  getter csum : Array(T)

  def initialize(array : Array(T))
    @size = array.size.to_i64
    @csum = Array.new(@size + 1, T.zero)
    @size.times { |i| @csum[i + 1] = @csum[i] + array[i] }
  end

  def [](l, r) : T
    get(l, r)
  end

  def [](range : Range(Int, Int)) : T
    left = range.begin
    right = range.exclusive? ? range.end : range.end + 1
    get(left, right)
  end

  def get(l, r) : T
    @csum[r] - @csum[l]
  end
end