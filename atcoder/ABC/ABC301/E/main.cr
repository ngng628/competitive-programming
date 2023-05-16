# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
macro make_array(s, x)
  Array.new({{ s[0] }}){
    {% if s[1..s.size].empty? %}; {{ x }}
    {% else %}; make_array({{ s[1..s.size] }}, {{ x }}) {% end %}
  }
end
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w, t = ints
s = (1..h).map { str.chars }
grid = Grid(Char).dydx4(s)

si, sj, gi, gj = -1_i64, -1_i64, -1_i64, -1_i64
okashis = Array({Int64, Int64}).new
h.times do |i|
  w.times do |j|
    if grid[i, j] == 'S'
      si, sj = i, j
    end
    if grid[i, j] == 'G'
      gi, gj = i, j
    end
    if grid[i, j] == 'o'
      okashis << {i, j}
    end
  end
end

dists = Hash({Int64, Int64}, Array(Array(Int64))).new
(okashis + [{si, sj}]).each do |fi, fj|
  que = Deque({Int64, Int64}).new [{fi, fj}]
  dist = make_array([h, w], OO)
  dist[fi][fj] = 0
  until que.empty?
    i, j = que.shift
    grid.each_neighbor(i, j) do |ni, nj|
      next if dist[ni][nj] != OO
      dist[ni][nj] = dist[i][j] + 1
      que << {ni, nj}
    end
  end
  dists[{fi, fj}] = dist
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



















struct Int; def self.bar; -1 end end
struct Char; def self.bar; '#' end end
class Grid(T)
  include Enumerable(T)

  def self.add(v1 : {Int, Int}, v2 : {Int, Int}); {v1[0] + v2[0], v1[1] + v2[1]} end
  def self.sub(v1 : {Int, Int}, v2 : {Int, Int}); {v1[0] - v2[0], v1[1] - v2[1]} end
 
  UP = {-1, 0}
  LEFT = {0, -1}
  DOWN = {1, 0}
  RIGHT = {0, 1}
  DYDX2 = [DOWN, RIGHT]
  DYDX4 = [UP, LEFT, DOWN, RIGHT]

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

  alias Pos = {Int32, Int32}
  getter h : Int32, w : Int32
  getter delta : Array(Pos)
  @s : Array(T)
  @bar : T

  def self.dydx2(s : Array(Array(T)))
    new(s, DYDX2)
  end

  def self.dydx4(s : Array(Array(T)))
    new(s, DYDX4)
  end

  def self.dydx8(s : Array(Array(T)))
    new(s, DYDX8)
  end

  def initialize(s : Array(Array(T)), @delta)
    @h = s.size
    @w = s[0].size
    @s = s.flatten
    @bar = T.bar
  end

  # 位置 `pos` がグリッドの範囲外なら `true` を返します。
  #
  # ```
  # grid.over?({-1, 0}) # => true
  # grid.over?({h + 10, w + 10}) # => true
  # grid.over?({0, 0}) # => false
  # ```
  @[AlwaysInline]
  def over?(pos) : Bool
    over?(pos[0], pos[1])
  end

  # 位置 `(y, x)` がグリッドの範囲外なら `true` を返します。
  #
  # ```
  # grid.over?(-1, 0) # => true
  # grid.over?(h + 10, w + 10) # => true
  # grid.over?(0, 0) # => false
  # ```
  @[AlwaysInline]
  def over?(y, x) : Bool
    y < 0 || y >= @h || x < 0 || x >= @w
  end

  # 位置 `pos` が進入禁止なら `true` を返します。
  #
  # ```
  # ..
  # .#
  #
  # grid.barrd?({0, 0}) # => false
  # grid.barrd?({1, 1}) # => true
  # ```
  @[AlwaysInline]
  def barred?(pos) : Bool
    barred?(pos[0], pos[1])
  end

  # 位置 `(y, x)` が進入禁止なら `true` を返します。
  #
  # ```
  # ..
  # .#
  #
  # grid.barrd?(0, 0) # => false
  # grid.barrd?(1, 1) # => true
  # ```
  @[AlwaysInline]
  def barred?(y : Int, x : Int) : Bool
    over?(y, x) || self[y, x] == @bar
  end

  # 位置 `pos` が通行可能なら `true` を返します。
  #
  # ```
  # ..
  # .#
  #
  # grid.free?({0, 0}) # => true
  # grid.free?({1, 1}) # => false
  # ```
  @[AlwaysInline]
  def free?(pos) : Bool
    !barred?(pos)
  end

  # 位置 `(y, x)` が通行可能なら `true` を返します。
  #
  # ```
  # ..
  # .#
  #
  # grid.free?(0, 0) # => true
  # grid.free?(1, 1) # => false
  # ```
  @[AlwaysInline]
  def free?(y : Int, x : Int) : Bool
    !barred?(y, x)
  end

  def each(& : T ->)
    i = 0
    while i < h
      j = 0
      while j < w
        yield s[i][j]
        j += 1
      end
      i += 1
    end
  end

  def each_with_index(&)
    i = 0_i64
    while i < h
      j = 0_i64
      while j < w
        yield s[i][j], {i, j}
        j += 1
      end
      i += 1
    end
  end

  # 位置 `(y, x)` の近傍で、侵入可能な位置を列挙します。
  #
  # ```
  # grid = Grid.dydx([".#.", "...", "...")
  #
  # grid.each_neighbor(1, 1) do |ny, nx|
  # end
  # ```
  def each_neighbor(y : Int, x : Int, &)
    i = 0
    while i < @delta.size
      ny = y + @delta[i][0]
      nx = x + @delta[i][1]
      yield ny, nx if free?(ny, nx)
      i += 1
    end
  end

  # 位置 `(y, x)` の近傍で、侵入可能な位置を方向とともに列挙します。
  #
  # ```
  # grid = Grid.dydx([".#.", "...", "...")
  #
  # grid.each_neighbor(1, 1) do |ny, nx, dir|
  # end
  # ```
  def each_neighbor_with_direction(y : Int, x : Int, &)
    i = 0
    while i < @delta.size
      ny = y + @delta[i][0]
      nx = x + @delta[i][1]
      yield ny, nx, i if free?(ny, nx)
      i += 1
    end
  end

  def fetch(y : Int, x : Int, default : T)
    over?(y, x) ? default : self[y, x]
  end

  def to_a : Array(Array(T))
    a = Array.new(@h) { Array(T).new(@w) }
    @h.times do |i|
      @w.times do |j|
        a[i] << self[i, j]
      end
    end
    a
  end

  def to_s(io : IO)
    @h.times do |i|
      @w.times do |j|
        io << ' ' if j != 0
        io << self[i, j]
      end
      io << '\n'
    end
    io
  end

  def [](pos : {Int, Int})
    self[pos[0], pos[1]]
  end

  def [](y : Int, x : Int)
    @s[y*@w + x]
  end

  def []=(pos : {Int, Int}, c : T)
    self[pos[0], pos[1]] = c
  end

  def []=(y : Int, x : Int, c : T)
    @s[y*@w + x] = c
  end
end
