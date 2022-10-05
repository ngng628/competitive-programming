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
act = [[0, 0, 0] of Int64].concat((0...n).map{ ints })

dp = Array.new(n + 1){ Array.new(3){ 0_i64 } }
(1..n).each do |i|
  3.times do |j|
    dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + act[i][j]
  end
end

puts dp[n].max