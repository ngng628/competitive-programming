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

n, w_lim = ints
items = [[0, 0] of Int64].concat (1..n).map{ ints }

dp = Array.new(n + 1){ Array.new(w_lim + 1){ 0_i64 } }
(1..n).each do |i|
  (0..w_lim).each do |w|
    wi, vi = items[i]
    dp[i][w] = dp[i - 1][w]
    chmax(dp[i][w], dp[i - 1][w - wi] + vi) if w - wi >= 0
  end
end

puts dp[n].max