# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
record Vec2, x : Float64, y : Float64 do
  def length; Math.sqrt(x**2 + y**2) end
  def -(other : Vec2); Vec2.new(x - other.x, y - other.y) end
end
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．


n, m = ints
towns = [Vec2.new(0.0, 0.0)] + Array.new(n){ x, y = ints; Vec2.new(x.to_f64, y.to_f64) }
chests = Array.new(m){ x, y = ints; Vec2.new(x.to_f64, y.to_f64) }
n += 1

dist = (0...n + m).map do |i|
  (0...n + m).map do |j|
    from = i < n ? towns[i] : chests[i - n]
    to = j < n ? towns[j] : chests[j - n]
    (to - from).length
  end
end

dp = Array.new(1 << (n + m)){ Array.new(n + m){ Float64::INFINITY } }
dp[0][0] = 0.0
(1 << (n + m)).times do |s|
  (n + m).times do |to|
    (n + m).times do |from|
      next if from == to
      next if s != 0 && s.bit(from) == 0
      next if s.bit(to) == 1

      n_accelerators = (s.bits(n..n + m)).popcount

      chmin(dp[s | (1 << to)][to], dp[s][from] + dist[from][to] / 2**n_accelerators)
    end
  end
end

ans = (1 << m).times.min_of do |t|
  s = ((1 << n) - 1) | (t << n)
  dp[s][0]
end

puts ans