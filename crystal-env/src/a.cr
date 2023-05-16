# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
macro make_array(s, x)
  Array.new({{ s[0] }}){
    {% if s[1..s.size].empty? %}; {{ x }}
    {% else %}; make_array({{ s[1..s.size] }}, {{ x }}) {% end %}
  }
end
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

require "nglib/grid"
require "nglib/data-structure/static-range-sum"

h, w, t = ints
s = (1..h).map { str.chars }
grid = NgLib::Grid(Char).dydx4(s)

si, sj = grid.index!('S').map &.to_i64
gi, gj = grid.index!('G').map &.to_i64
okashis = Array({Int64, Int64}).new
grid.each_with_coord do |c, (i, j)|
  okashis << {i.to_i64, j.to_i64} if c == 'o'
end

dists = Hash({Int64, Int64}, Array(Array(Int64))).new
(okashis + [{si, sj}]).each do |fi, fj|
  dists[{fi, fj}] = grid.shortest_path({fi, fj})
end

n = okashis.size
dp = make_array([1 << n, n], OO)
n.times do |i|
  y, x = okashis[i]
  dp[(1 << i)][i] = dists[{si, sj}][y][x]
end
(1 << n).times do |mask|
  n.times do |i|
    n.times do |j|
      if mask != 0 && mask.bit(j) == 0
        next
      end
      if mask.bit(i) == 0
        y, x = okashis[i]
        chmin(dp[mask | (1 << i)][i], dp[mask][j] + dists[okashis[j]][y][x])
      end
    end
  end
end

ans = -1_i64
(1 << n).times do |mask|
  n.times do |i|
    if dp[mask][i] + dists[okashis[i]][gi][gj] <= t
      chmax(ans, mask.to_s(2).count('1'))
    end
  end
end
chmax(ans, 0_i64) if dists[{si, sj}][gi][gj] <= t
puts ans
