# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
macro make_array(s, x)
  Array.new({{ s[0] }}){
    {% if s[1..s.size].empty? %}; {{ x }}
    {% else %}; make_array({{ s[1..s.size] }}, {{ x }}) {% end %}
  }
end
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
a = [0_i64].concat(ints)

# dp[i][j[k] := i までで、j を作るための必要な操作回数。ただし a[i] を(k ? 選ぶ : 選ばない)
dp = make_array([m + 3210, 2], OO)
dp[0][0] = 1
dp[0][1] = 0
(1..n).each do |i|
  dp2 = make_array([m + 3010, 2], OO)
  (0..m).each do |j|
    dp2[j][0] = Math.min(dp[j][0], dp[j][1] + 1)
    dp2[j + a[i]][1] = Math.min(dp[j][0], dp[j][1])
  end
  dp = dp2
end

(1..m).each do |x|
  ans = Math.min(dp[x][0], dp[x][1])
  puts ans >= OO ? -1 : ans
end