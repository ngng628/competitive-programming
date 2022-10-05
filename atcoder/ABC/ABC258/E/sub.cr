alias I32 = Int32
alias I64 = Int64
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : I64); read_line.to_i64 - 1 end
def ints(offset : I64); read_line.split.map{ |x| x.to_i64 - offset} end
def str; read_line.chomp end
def min(a : I64, b : I64) : I64; a < b ? a : b end
def max(a : I64, b : I64) : I64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
def rng(a : I64, b : I64) : I64; (a...b).each{ |i| yield(i) } end
DYDX4 = [ {1, 0}, {-1, 0}, {0, 1}, {0, -1} ]
DYDX8 = [ {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} ]

class StaticRangeSum(T)
  def initialize(@array : Array(T))
    @csum = @array.accumulate(0i64.as(T)).as(Array(T))
    @n = @array.size.to_i64.as(I64)
  end

  def get(l, r) : T
    @csum[r] - @csum[l]
  end
end

a = [1, 1, 2, 3, 5, 7] of I64
n = a.size
csum = StaticRangeSum.new(a)
puts csum.get(0, n)