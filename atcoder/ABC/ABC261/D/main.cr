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
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
x = ints
bonus = Array.new(n + 1){ 0_i64 }
m.times do
  c, y = ints
  bonus[c] += y
end

dp = Array.new(n + 1){ Array.new(2, -OO) }
dp[0][0] = dp[0][1] = 0_i64
mx2 = -OO
(1..n).each do |i|
  dp2 = Array.new(n + 1){ Array.new(2, -OO) }
  mx = -OO

  dp2[0][0] = mx2
  dp2[0][1] = mx2
  (1..n).each do |j|
    dp2[j][1] = -OO
    dp2[j][0] = dp[j - 1].max + bonus[j] + x[i - 1]
    chmax(mx, dp2[j].max)
  end

  mx2 = mx
  dp = dp2
end

ans = dp.max_of{ |x| x.max }
puts ans