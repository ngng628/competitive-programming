# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
def min(x : Int64, y : Int64) : Int64; x < y ? x : y end
def max(x : Int64, y : Int64) : Int64; x > y ? x : y end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
MOD = 10_i64**9 + 7
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w = ints
s = (1..h).map{ str }
grid = Grid.new(h, w, s, [Grid::RIGHT, Grid::DOWN])

dp = Array.new(h){ |i| Array.new(w){ |j| i == 0 && j == 0 ? 1_i64 : 0_i64 } }
grid.each_with_index do |c, (i, j)|
  next if c == '#'
  grid.each_neighbor(i, j) do |ni, nj|
    dp[ni][nj] += dp[i][j]
    dp[ni][nj] %= MOD
  end
end

puts dp[h - 1][w - 1]



class Grid
  include Enumerable(Char)
 
  LEFT = {-1_i64, 0_i64}
  RIGHT = {1_i64, 0_i64}
  UP = {0_i64, -1_i64}
  DOWN = {0_i64, 1_i64}
  DYDX4 = [LEFT, RIGHT, UP, DOWN]
  DYDX8 = [UP, UP+RIGHT, RIGHT, DOWN+RIGHT, DOWN, DOWN+LEFT, LEFT, UP+LEFT]
 
  alias Pii = {Int64, Int64}
  getter h : Int64, w : Int64
  getter s : Array(Array(Char))
  getter delta : Array(Pii)
  def self.dydx4(h, w, s : Array(Array(Char))); new h, w, s, DYDX4 end
  def self.dydx4(h, w, s : Array(String)); new h, w, s, DYDX4 end
  def self.dydx8(h, w, s : Array(Array(Char))); new h, w, s, dydx8 end
  def self.dydx8(h, w, s : Array(String)); new h, w, s, DYDX8 end
  def initialize(@h, @w, @s : Array(Array(Char)), @delta); end
  def initialize(@h, @w, ss : Array(String), @delta); @s = ss.map{ |e| e.chars }.to_a end
  def over?(y, x) : Bool; y < 0 || y >= @h || x < 0 || x >= @w end
  def each(& : Char ->); i = 0; while i < h; j = 0; while j < w; yield s[i][j]; j += 1; end; i += 1; end; end
  def each_with_index(& : {Char, Pii} ->)
    i = 0_i64; while i < h; j = 0_i64; while j < w; t = {s[i][j], {i, j}}; yield t; j += 1; end; i += 1 end
  end
  def each_neighbor(y : Int, x : Int)
    i = 0
    while i < @delta.size
      res = {y + @delta[i][0], x + @delta[i][1]}
      yield res if !over?(res[0], res[1]) && s[res[0]][res[1]] != '#'
      i += 1
    end
  end
  def [](y : Int); s[y] end
end