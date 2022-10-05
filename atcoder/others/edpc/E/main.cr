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
items = [[0_i64, 0_i64]].concat((1..n).map{ ints })

v_max = n * 10**3
dp = Array.new(n + 1){ Array.new(v_max + 1){ OO } }
dp[0][0] = 0
(1..n).each do |i|
  (0..v_max).each do |v|
    wi, vi = items[i]
    dp[i][v] = dp[i - 1][v]
    chmin(dp[i][v], dp[i - 1][v - vi] + wi) if v - vi >= 0
  end
end

ans = 0
(0..v_max).each do |v|
  ans = v if dp[n][v] <= w_lim
end

puts ans