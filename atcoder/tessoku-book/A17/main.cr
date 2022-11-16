# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints
b = ints

dp = Array.new(n + 3){ |i| i == 0 ? 0_i64 : OO }
memo = Array(Int64?).new(n + 3){ nil }
(0_i64...n).each do |i|
  if i < n - 1 && dp[i + 1] > dp[i] + a[i]
    dp[i + 1] = dp[i] + a[i]
    memo[i + 1] = i
  end

  if i < n - 2 && dp[i + 2] > dp[i] + b[i]
    dp[i + 2] = dp[i] + b[i]
    memo[i + 2] = i
  end
end

ans = Array(Int64).new
now = n - 1
until now.nil?
  ans << now.not_nil! + 1
  now = memo[now.not_nil!]
end

puts ans.size
puts ans.reverse.join(" ")