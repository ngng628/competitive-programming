# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
a = (1..m).map{ str.delete(" ").to_i32(base: 2) }

# dp[i][s] = i 枚目までのクーポンで 商品 s を揃えるために必要な最小金額
dp = Array.new(m + 1){ |i| Array.new(1 << n){ |s| i == 0 && s == 0 ? 0_i64 : OO } }
m.times do |i|
  (1 << n).times do |s|
    chmin(dp[i + 1][s | a[i]], dp[i][s] + 1)
    chmin(dp[i + 1][s], dp[i][s])
  end
end

ans = dp.last.last
puts ans == OO ? -1 : ans