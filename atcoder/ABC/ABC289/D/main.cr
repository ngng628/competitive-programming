# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints
m = int
b = Set.new(ints)
x = int

dp = Array.new(x + 1) { false }
dp[0] = true
(0..x).each do |i|
  if b.includes?(i)
    dp[i] = false
  else
    a.each do |ai|
      dp[i] |= dp[i - ai] if i >= ai
    end
  end
end

puts dp[x] ? "Yes" : "No"
