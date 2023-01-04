# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m, k = ints
edges = Array.new(m) do
  a, b, c = ints
  a -= 1; b -= 1
  Edge.new(a, b, c)
end
e = ints -1

# 都市 v に到達するための最小値
dp = Array.new(n){ OO }
dp[0] = 0_i64
e.map{ |i| edges[i] }.each do |(a, b, c)|
  dp[b] = Math.min(dp[b], dp[a] + c)
end

ans = dp[n - 1]
puts ans >= OO ? -1 : ans




struct Edge
  @data : {Int64, Int64, Int64}

  def initialize(f : Int64, t : Int64, w : Int64)
    @data = {f, t, w}
  end

  def self.from; @data[0] end
  def self.to; @data[1] end
  def self.weight; @data[2] end
  def [](i : Int); @data[i] end
end