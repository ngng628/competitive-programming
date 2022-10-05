# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
blocks = (1..n).map{ ints }
indices = (0...n).to_a.sort{ |i, j| blocks[i][0] + blocks[i][1] <=> blocks[j][0] + blocks[j][1] }
blocks = indices.map{ |i| blocks[i] }

dp = Array.new(n + 1){ |i| Array.new(2*10**4 + 1){ |j| i == 0 && j == 0 ? 0_i64 : -OO } }
blocks.each_with_index do |(w, s, v), i|
  (0..2*10**4).each do |j|
    chmax(dp[i + 1][j], dp[i][j])
    chmax(dp[i + 1][j], dp[i + 1][j - 1]) if j >= 1
    chmax(dp[i + 1][j], dp[i][j - w] + v) if j >= w && j - w <= s
  end
end

puts dp.last.max? || 0_i64