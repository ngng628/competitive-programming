# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int, b : Int) : Int; a < b ? a : b end
def max(a : Int, b : Int) : Int; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
          {-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, k = ints
k -= 1
a = ints.sort

getMinus = ->(x : Int64) do
  neg = Array(Int64).new
  pos = Array(Int64).new
  a.each do |x|
    neg << x if x < 0
    pos << x if x > 0
  end

  j = 0
  neg.sum do |neg_i|
    while j < pos.size && neg_i * pos[j] >= x
      j += 1
    end
    pos.size.to_i64 - j
  end
end

getZeros = ->(x : Int64) do
  n_zeros = a.count(0_i64).to_i64
  (n - n_zeros .. n - 1).sum.to_i64
end

getPlus = ->(x : Int64) do
  neg = Array(Int64).new
  pos = Array(Int64).new
  n.times do |i|
    neg << -a[n - i - 1] if a[n - i - 1] < 0
    pos << a[i] if a[i] > 0
  end
  
  j = neg.size - 1
  sum = neg.size.times.sum do |i|
    while i < j && neg[i] * neg[j] >= x
      j -= 1
    end
    max(0_i64, (j - i).to_i64)
  end

  j = pos.size - 1
  sum += pos.size.times.sum do |i|
    while i < j && pos[i] * pos[j] >= x
      j -= 1
    end
    max(0, j - i)
  end

  sum
end

getCount = ->(x : Int64) do
  res = getMinus.call(x)
  res += getZeros.call(x) if x >= 1
  res += getPlus.call(x) if x > 1
  res
end

ok = -OO
ng = OO
while (ok - ng).abs > 1
  mid = (ok + ng) // 2
  if getCount.call(mid) <= k
    ok = mid
  else
    ng = mid
  end
end

puts ok