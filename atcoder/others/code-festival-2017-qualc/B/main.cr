# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints

EVEN = 0
ODD = 1

dp = Array.new(n + 1){ [0] * 2 }
dp[0][ODD] = 1
a.each_with_index(1) do |ai, i|
  if ai.odd?
    dp[i][EVEN] = 2 * dp[i - 1][ODD] + 3 * dp[i - 1][EVEN]
    dp[i][ODD] = dp[i - 1][ODD]
  else
    dp[i][EVEN] = dp[i - 1][ODD] + 3 * dp[i - 1][EVEN]
    dp[i][ODD] = 2 * dp[i - 1][ODD]
  end
end

puts dp[n][EVEN]
