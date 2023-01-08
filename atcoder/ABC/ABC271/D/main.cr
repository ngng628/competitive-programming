# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, s = ints
cards = (1..n).map{ a, b = ints; {a, b} }

dp = Array.new(n + 1){ [false] * (s + 1) }
dp[0][0] = true
cards.each_with_index(1) do |(a, b), i|
  (0_i64..s).each do |x|
    ca = x - a >= 0 && dp[i - 1][x - a]
    cb = x - b >= 0 && dp[i - 1][x - b]
    dp[i][x] = ca | cb
  end
end

(puts "No") + exit unless dp[n][s]

index = n
now = s
route = [] of Char
until now == 0
  a, b = cards[index - 1]
  if dp[index - 1][now - a]
    route << 'H'
    now -= a
  else
    route << 'T'
    now -= b
  end
  index -= 1
end

puts "Yes"
puts route.reverse.join