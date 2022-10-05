# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
a = [-OO].concat(ints)
# dp[i][j] = i 番目までで j 個選んでいるときの総和の最大値
dp = Array.new(n + 1){ Array(Int64).new(m + 1){ -OO } }
dp[0][0] = 0
(1..n).each do |i|
  (0..m).each do |j|
    chmax(dp[i][j], dp[i - 1][j])
    chmax(dp[i][j], dp[i - 1][j - 1] + (j*a[i])) if j - 1 >= 0
  end
end

puts dp[n][m]