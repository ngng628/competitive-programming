# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
bonus = Array.new(10**5 + 1){ Array(Int64).new(5){ 0_i64 } }
n.times do
  t, x, a = ints
  bonus[t][x] = a
end

dp = Array.new(10**5 + 1){ Array(Int64).new(5){ -OO } }
dp[0][0] = 0_i64
(1..10**5).each do |t|
  5.times do |x|
    chmax(dp[t][x], dp[t - 1][x - 1] + bonus[t][x]) if x - 1 >= 0
    chmax(dp[t][x], dp[t - 1][x] + bonus[t][x])
    chmax(dp[t][x], dp[t - 1][x + 1] + bonus[t][x]) if x + 1 <= 4
  end
end

puts dp[10**5].max