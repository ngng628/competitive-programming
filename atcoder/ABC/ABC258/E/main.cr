# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

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
  getter size : I64
  getter csum : Array(T)

  def initialize(array : Array(T))
    @size = array.size.to_i64
    @csum = Array.new(@size + 1, 0_i64.as(T))
    @size.times { |i| @csum[i + 1] = @csum[i] + array[i] }
  end

  def get(l, r) : T
    @csum[r] - @csum[l]
  end
end

# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, q, x = ints
w = ints

n_potatoes = Array(I64).new(n, 0)
indices = Array.new(n, 0)
csum = StaticRangeSum.new(w + w)
n.times do |i|
  s = csum.get(i, i + n)
  lim = x % s
  offset = n * (x // s)
  ok = i + n
  ng = i - 1
  while (ok - ng).abs > 1
    mid = (ok + ng) // 2
    if csum.get(i, mid) >= lim
      ok = mid
    else
      ng = mid
    end
  end
  n_potatoes[i] = ok - i + offset
  indices[i] = (ok % n).to_i
end

index = Array.new(n, 0)
value = Array.new(0, 0)
now = 0
cur = 0
while index[now] == 0
  value.push(now)
  index[now] = (cur += 1)
  now = indices[now]
end

cycle = cur - index[now] + 1
margin = index[now]

q.times do
  k = int(-1)
  if k >= margin
    k = (k - margin) % cycle + margin
  end
  puts n_potatoes[value[k]]
end