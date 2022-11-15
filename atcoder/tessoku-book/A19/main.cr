# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, w_lim = ints
boxes = (1..n).map{ i = ints; {i[0], i[1]} }

dp = Array.new(w_lim + 1){ 0_i64 }
boxes.each do |w, v|
  (0..w_lim).each do |i|
    dp[i] = Math.max(dp[i], dp[i - w] + v) if i - w >= 0
  end
end

puts dp.max