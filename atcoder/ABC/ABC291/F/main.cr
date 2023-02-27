# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
s = (1..n).map { str.chars }
dp_0 = Array.new(n + m + 10) { OO }
dp_0[0] = 0
n.times do |i|
  m.times do |j|
    if s[i][j] == '1'
      chmin(dp_0[i + j + 1], dp_0[i] + 1)
    end
  end
end

dp_g = Array.new(n + m + 10) { OO }
dp_g[n - 1] = 0
(n - 1).downto(0) do |i|
  m.times do |j|
    break if i - j - 1 < 0
    if s[i - j - 1][j] == '1'
      chmin(dp_g[i - j - 1], dp_g[i] + 1)
    end
  end
end

answers = Array(Int64).new((1...n - 1).size)
(1...n - 1).each do |k|
  ans = OO
  (m + 2).times do |back|
    (m + 2).times do |front|
      next if back == 0 || front == 0
      u = Math.max(0_i64, k - back)
      v = Math.min(k + front, n - 1)

      d = v - u
      if d <= m && s[u][d - 1] == '1'
        chmin(ans, dp_0[u] + 1 + dp_g[v])
      end
    end
  end

  answers << (ans >= OO ? -1_i64 : ans)
end

puts answers.join(" ")
