# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int64, b : Int64) : Int64; a < b ? a : b end
def max(a : Int64, b : Int64) : Int64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
          {-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
ab = n.times.map{ ints }.to_a
a = ab.map{ |(x, y)| x }.to_a
b = ab.map{ |(x, y)| y }.to_a
A = 0
B = 1
AB = 2

dp = Array(Array(Int64)).new(n + 1){ |i| Array(Int64).new(3){ |j| 0_i64 } }
n.times do |i|
  
  dp[i + 1][A] += dp[i][A] if a[i - 1] == a[i] - 1
  dp[i + 1][A] += dp[i][B] if b[i - 1] == a[i] - 1
  dp[i + 1][B] += dp[i][A] if a[i - 1] == b[i] - 1
  dp[i + 1][B] += dp[i][A] if b[i - 1] == b[i] - 1
  puts dp[i + 1][A] + dp[i + 1][B]
end