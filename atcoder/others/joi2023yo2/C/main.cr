# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w = ints
a = (1..h).map{ ints }
grid = Grid.dydx4(h, w, a)

if grid.all?{ |c| c == grid[0, 0] }
  puts h * w
  exit
end

ut = DisjointSet.new(h * w)
h.times do |i|
  w.times do |j|
    grid.each_neighbor(i, j) do |ni, nj|
      next if a[i][j] != a[ni][nj]
      ut.unite(w*i + j, w*ni + nj)
    end
  end
end

graph = Hash(Int64, Set(Int64)).new
h.times do |i|
  w.times do |j|
    grid.each_neighbor(i, j) do |ni, nj|
      next if a[i][j] == a[ni][nj]
      u = ut.leader(w*i + j)
      v = ut.leader(w*ni + nj)

      graph[u] = Set(Int64).new unless graph.has_key?(u)
      graph[v] = Set(Int64).new unless graph.has_key?(v)

      unless graph[u].includes?(v)
        graph[u] << v
        graph[v] << u
      end
    end
  end
end

ans = 0_i64
graph.each_key do |v1|
   hash = Hash(Int64, Int64).new(ut.size(v1))
  graph[v1].each do |v2|
    c = a[v2 // w][v2 % w]
    hash[c] += ut.size(v2)
  end
  chmax(ans, hash.values.max)
end

puts ans






class Grid
  include Enumerable(Int64)
 
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
  getter s : Array(Array(Int64))
  getter delta : Array(Pii)
  def self.dydx4(h, w, s : Array(Array(Int64))); new h, w, s, DYDX4 end
  def self.dydx8(h, w, s : Array(Array(Int64))); new h, w, s, dydx8 end
  def initialize(@h, @w, @s : Array(Array(Int64)), @delta); end
  def over?(pos) : Bool; pos[0] < 0 || pos[0] >= @h || pos[1] < 0 || pos[1] >= @w end
  def over?(y, x) : Bool; y < 0 || y >= @h || x < 0 || x >= @w end
  def barred?(pos); over?(pos[0], pos[1]) || s[pos[0]][pos[1]] == -1 end
  def barred?(y : Int, x : Int); over?(y, x) || s[y][x] == -1 end
  def free?(pos); !barred?(pos) end
  def free?(y : Int, x : Int); !barred?(y, x) end
  def each(& : Int64 ->); i = 0; while i < h; j = 0; while j < w; yield s[i][j]; j += 1; end; i += 1; end; end
  def each_with_index(& : {Int64, Pii} ->)
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

  def [](pos : {Int, Int}); s[pos[0]][pos[1]] end
  def [](y : Int, x : Int); s[y][x] end
  def []=(pos : {Int, Int}, c : Int64); s[pos[0]][pos[1]] = c end
  def []=(y : Int, x : Int, c : Int64); s[y][x] = c end
end


class DisjointSet
  @n : Int64
  @parent_or_size : Array(Int64)

  def initialize
    @n = 0
    @parent_or_size = Array(Int64).new
  end

  def initialize(@n : Int64)
    @parent_or_size = Array(Int64).new(n, -1_i64)
  end

  def unite(a : Int64, b : Int64) : Int64
    x = leader(a)
    y = leader(b)
    return x.to_i64 if x == y
    if -@parent_or_size[x] < -@parent_or_size[y]
      x, y = y, x
    end
    @parent_or_size[x] += @parent_or_size[y]
    @parent_or_size[y] = x
    x.to_i64
  end

  def equiv?(a : Int64, b : Int64) : Bool
    leader(a) == leader(b)
  end

  def leader(a : Int64) : Int64
    return a.to_i64 if @parent_or_size[a] < 0
    @parent_or_size[a] = leader(@parent_or_size[a])
    @parent_or_size[a].to_i64
  end

  def size(a : Int64) : Int64
    -@parent_or_size[leader(a)].to_i64
  end

  def groups : Array(Array(Int64)) | Nil
    leader_buf = Array(Int64).new(@n, 0_i64)
    group_size = Array(Int64).new(@n, 0_i64)
    @n.times do |i|
      leader_buf[i] = leader(i)
      group_size[leader_buf[i]] += 1
    end
    res = Array.new(@n){ Array(Int64).new() }
    @n.times do |i|
      res[leader_buf[i]] << i.to_i64
    end
    res.delete([] of Int64)
    res
  end
end
