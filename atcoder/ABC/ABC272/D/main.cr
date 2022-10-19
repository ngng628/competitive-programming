# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints

s = Array.new(n){ Array(Char).new(n){ '.' }}

dydxs = Array({Int64, Int64}).new
(10_i64**3).times do |dy|
  (10_i64**3).times do |dx|
    if dy**2 + dx**2 == m
      dydxs << {dy, dx}
      dydxs << {-dy, dx}
      dydxs << {dy, -dx}
      dydxs << {-dy, -dx}
    end
  end
end

que = Deque.new [{0_i64, 0_i64}]
dist = Array.new(n){ |i| Array.new(n){ |j| {i, j} == {0_i64, 0_i64} ? 0_i64 : OO } }
grid = Grid.new(n, n, s, dydxs)
until que.empty?
  y, x = que.shift
  grid.each_neighbor(y, x) do |ny, nx|
    next if dist[ny][nx] != OO
    dist[ny][nx] = dist[y][x].not_nil! + 1
    que << {ny, nx}
  end
end

n.times do |i|
  puts dist[i].map{ |d| d == OO ? -1_i64 : d }.join(" ")
end


class Grid
  include Enumerable(Char)
 
  UP = {-1_i64, 0_i64}
  DOWN = {1_i64, 0_i64}
  LEFT = {0_i64, -1_i64}
  RIGHT = {0_i64, 1_i64}
  DYDX4 = [LEFT, RIGHT, UP, DOWN]

  def self.add(v1 : {Int, Int}, v2 : {Int, Int}); {v1[0] + v2[0], v1[1] + v2[1]} end
  def self.sub(v1 : {Int, Int}, v2 : {Int, Int}); {v1[0] - v2[0], v1[1] - v2[1]} end

  DYDX8 = [
    UP,
    add(UP, RIGHT),
    RIGHT,
    add(DOWN, RIGHT),
    DOWN,
    add(DOWN, LEFT),
    LEFT,
    add(UP, LEFT),
  ]

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
  def over?(pos) : Bool; pos[0] < 0 || pos[0] >= @h || pos[1] < 0 || pos[1] >= @w end
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
  
  def [](pos : {Int, Int}); s[pos[0]][pos[1]] end
  def [](y : Int, x : Int); s[y][x] end
  def []=(pos : {Int, Int}, c : Char); s[pos[0]][pos[1]] = c end
  def []=(y : Int, x : Int, c : Char); s[y][x] = c end
end
