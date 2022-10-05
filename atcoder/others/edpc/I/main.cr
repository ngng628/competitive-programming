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
probs = [0.0] + read_line.split.map(&.to_f64)

dp = Array.new(n + 1){ Array.new(n + 1){ 0.0 } }
dp[0][0] = 1.0
(1..n).each do |i|
  (0..n).each do |r|
    dp[i][r] += dp[i - 1][r] * (1 - probs[i])
    dp[i][r] += dp[i - 1][r - 1] * probs[i] if r > 0
  end
end

ans = (0..n).sum do |r|
  w = n - r
  r > w ? dp[n][r] : 0.0
end

puts printf("%.10f", ans)