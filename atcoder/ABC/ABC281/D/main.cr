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

n, k, d = ints
a = ints

# dp[i][j][r] = i 番目までで、今 j 個選んでいて、総和のあまりが r であるものの最大値
dp = make_array([n + 1, d], -OO)
dp[0][0] = 0
n.times do |i|
  dp2 = make_array([n + 1, d], -OO)
  (0..k).each do |j|
    d.times do |r|
      chmax(dp2[j + 1][(r + a[i]) % d], dp[j][r] + a[i]) if j < k && dp[j][r] != -OO
      chmax(dp2[j][r], dp[j][r])
    end
  end
  dp = dp2
end

ans = dp[k][0]
puts ans <= -OO ? -1 : ans