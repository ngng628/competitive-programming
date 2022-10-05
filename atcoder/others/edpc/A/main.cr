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
h = [0_i64].concat(ints)
dp = [OO] * (n + 1)
dp[1] = 0
(1..n).each do |i|
  chmin(dp[i + 1], dp[i] + (h[i] - h[i + 1]).abs) if i + 1 <= n
  chmin(dp[i + 2], dp[i] + (h[i] - h[i + 2]).abs) if i + 2 <= n
end
puts dp[n]