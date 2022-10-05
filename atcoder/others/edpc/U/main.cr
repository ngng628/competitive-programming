# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = (1..n).map{ ints }

# dp[S] = すでにグループを決めたうさぎが S のときの最大値
# dp[S] = Math.max(dp[T], dp[T])
memo = Array(Int64?).new(1 << n){ nil }
dp = uninitialized Proc(Int64, Int64)
dp = ->(state : Int64) do
  return memo[state].not_nil! if memo[state]

  res = n.times.select{ |i| ((state >> i) & 1).odd? }.sum do |i|
    (i+1...n).select{ |j| ((state >> j) & 1).odd? }.sum do |j|
      a[i][j]
    end
  end

  t = state + 1
  while (t -= 1) >= 0
    t &= state
    next if t == state || t == 0
    chmax(res, dp.call(t) + dp.call(state ^ t))
  end

  memo[state] = res
end

puts dp.call((1_i64 << n) - 1)