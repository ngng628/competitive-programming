# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

s = str
t = str
puts s.lcs(t)

{% for type in [Array, String] %}
class {{ type }}
  # 最長共通部部分列の長さを返します。
  #
  # ```
  # "mynavi".lcs("monday") # => 3
  # [0, 1, 2].lcs([0, 2, 5, 8]) # => 2
  # ```
  def lcs(other : {{ type }}) : Int64
    n = self.size
    m = other.size
    dp = Array.new(n + 1){ Array.new(m + 1){ 0_i64 } }

    (1..n).each do |i|
      (1..m).each do |j|
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1 if self[i - 1] == other[j - 1]
      end
    end

    dp[n][m]
  end
end
{% end %}