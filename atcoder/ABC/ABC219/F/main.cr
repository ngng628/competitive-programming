# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

a = (1..4).map{ ints.map{ |e| e == 1 } }

ans = (1 << 16).times.count do |imask|
  next if imask == 0

  mask = Array.new(4) do |i|
    Array.new(4) do |j|
      index = 4*i + j
      imask.bit(index) == 1
    end
  end

  index = {-1, -1}
  4.times{ |i| 4.times{ |j| index = mask[i][j] ? {i, j} : index } }

  que = Deque.new([index])
  mask2 = Array.new(4){ [false] * 4 }
  mask2[index[0]][index[1]] = true
  grid = Grid(Bool).dydx4(4_i64, 4_i64, mask)
  until que.empty?
    i, j = que.shift
    grid.each_neighbor(i, j) do |(ni, nj)|
      next if mask2[ni][nj]
      mask2[ni][nj] = true
      que << {ni, nj}
    end
  end

  next if mask != mask2

  judge = Array.new(4) do |i|
    Array.new(4) do |j|
      mask[i][j] & a[i][j]
    end
  end

  next if judge != a

  4.times{ |i| mask[i].insert(0, false); mask[i].insert(-1, false) }
  mask.insert(0, [false] * 6)
  mask.insert(-1, [false] * 6)

  ut = DisjointSet.new(6 * 6)
  grid = Grid(Bool).dydx4(6_i64, 6_i64, mask)
  6.times do |i|
    6.times do |j|
      Grid::DYDX4.each do |(dy, dx)|
        ni = i + dy
        nj = j + dx

        next if grid.over?(ni, nj)

        if grid[i, j] == grid[ni, nj]
          ut.unite(6*i + j, 6*ni + nj)
        end
      end
    end
  end

  next if ut.groups.size != 2

  true
end

puts ans

struct Bool; def self.bar; false end end
struct Int; def self.bar; -1 end end
struct Char; def self.bar; '#' end end
class Grid(T)
  include Enumerable(T)
 
  UP = {-1, 0}
  LEFT = {0, -1}
  DOWN = {1, 0}
  RIGHT = {0, 1}
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

  alias Pii = {Int32, Int32}
  getter h : Int32, w : Int32
  getter s : Array(Array(T))
  getter delta : Array(Pii)
  @bar : T

  def self.dydx4(h, w, s : Array(Array(T))); new h, w, s, DYDX4 end
  def self.dydx8(h, w, s : Array(Array(T))); new h, w, s, DYDX8 end

  def initialize(height, width, @s : Array(Array(T)), @delta)
    @h = height.to_i32
    @w = height.to_i32
    @bar = T.bar
  end

  def over?(pos) : T; pos[0] < 0 || pos[0] >= @h || pos[1] < 0 || pos[1] >= @w end
  def over?(y, x) : T; y < 0 || y >= @h || x < 0 || x >= @w end
  def barred?(pos); over?(pos[0], pos[1]) || s[pos[0]][pos[1]] == @bar end
  def barred?(y : Int, x : Int); over?(y, x) || s[y][x] == @bar end
  def free?(pos); !barred?(pos) end
  def free?(y : Int, x : Int); !barred?(y, x) end
  def each(& : T ->); i = 0; while i < h; j = 0; while j < w; yield s[i][j]; j += 1; end; i += 1; end; end
  def each_with_index(& : {T, Pii} ->)
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

  def fetch(y : Int, x : Int, default : T)
    over?(y, x) ? default : s[y][x]
  end

  def [](pos : {Int, Int}); s[pos[0]][pos[1]] end
  def [](y : Int, x : Int); s[y][x] end
  def []=(pos : {Int, Int}, c : T); s[pos[0]][pos[1]] = c end
  def []=(y : Int, x : Int, c : T); s[y][x] = c end
end

class DisjointSet
  @n : Int32
  @parent_or_size : Array(Int32)

  def initialize
    @n = 0
    @parent_or_size = Array(Int32).new
  end

  def initialize(size : Int)
    @n = size.to_i32
    @parent_or_size = [-1] * size
  end

  def unite(a : Int, b : Int) : Int32
    x = leader(a)
    y = leader(b)
    return x if x == y
    if -@parent_or_size[x] < -@parent_or_size[y]
      x, y = y, x
    end
    @parent_or_size[x] += @parent_or_size[y]
    @parent_or_size[y] = x
    x
  end

  def equiv?(a : Int, b : Int) : Bool
    leader(a) == leader(b)
  end

  def leader(a : Int) : Int32
    return a.to_i32 if @parent_or_size[a] < 0
    @parent_or_size[a] = leader(@parent_or_size[a])
    @parent_or_size[a]
  end

  def size(a : Int) : Int32
    -@parent_or_size[leader(a)]
  end

  def groups : Array(Array(Int32)) | Nil
    leader_buf = [0] * @n
    group_size = [0] * @n
    @n.times do |i|
      leader_buf[i] = leader(i)
      group_size[leader_buf[i]] += 1
    end
    res = Array.new(@n){ [] of Int32 }
    @n.times do |i|
      res[leader_buf[i]] << i
    end
    res.delete([] of Int32)
    res
  end
end