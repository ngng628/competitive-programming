# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w = ints
c = (1..h).map{ str }
grid = Grid.dydx4(h, w, c)
si, sj = grid.start

ok = false
grid.each_neighbor(si, sj) do |i1, j1|
  grid.each_neighbor(i1, j1) do |i2, j2|
    next if i2 == si && j2 == sj

    que = Deque.new [{i2, j2}]
    dist = Array.new(h){ |i| Array.new(w){ |j| {i, j}.in?([{i1, j1}, {i2, j2}]) ? 1_i64 : OO } }

    until que.empty?
      y, x = que.shift
      grid.each_neighbor(y, x) do |ny, nx|
        next if dist[ny][nx] != OO
        dist[ny][nx] = dist[y][x] + 1
        que << {ny, nx}
      end
    end

    ok = true if dist[si][sj] != OO
  end
end

puts ok ? "Yes" : "No"






class Grid
  include Enumerable(Char)
 
  UP = {-1_i64, 0_i64}
  LEFT = {0_i64, -1_i64}
  DOWN = {1_i64, 0_i64}
  RIGHT = {0_i64, 1_i64}
  DYDX4 = [UP, LEFT, DOWN, RIGHT]

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
  def barred?(pos); over?(pos[0], pos[1]) || s[pos[0]][pos[1]] == '#' end
  def barred?(y : Int, x : Int); over?(y, x) || s[y][x] == '#' end
  def free?(pos); !barred(pos) end
  def free?(y : Int, x : Int); !barred(y, x) end
  def each(& : Char ->); i = 0; while i < h; j = 0; while j < w; yield s[i][j]; j += 1; end; i += 1; end; end
  def each_with_index(& : {Char, Pii} ->)
    i = 0_i64; while i < h; j = 0_i64; while j < w; t = {s[i][j], {i, j}}; yield t; j += 1; end; i += 1 end
  end
  def each_neighbor(y : Int, x : Int)
    i = 0
    while i < @delta.size
      res = {y + @delta[i][0], x + @delta[i][1]}
      yield res unless barred?(res)
      i += 1
    end
  end

  def start
    h.times do |i|
      w.times do |j|
        return i, j if s[i][j] == 'S'
      end
    end
    return -1, -1
  end

  def [](pos : {Int, Int}); s[pos[0]][pos[1]] end
  def [](y : Int, x : Int); s[y][x] end
  def []=(pos : {Int, Int}, c : Char); s[pos[0]][pos[1]] = c end
  def []=(y : Int, x : Int, c : Char); s[y][x] = c end
end