# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

r, c = ints -1

s = [
  "###############".chars,
  "#.............#".chars,
  "#.###########.#".chars,
  "#.#.........#.#".chars,
  "#.#.#######.#.#".chars,
  "#.#.#.....#.#.#".chars,
  "#.#.#.###.#.#.#".chars,
  "#.#.#.#.#.#.#.#".chars,
  "#.#.#.###.#.#.#".chars,
  "#.#.#.....#.#.#".chars,
  "#.#.#######.#.#".chars,
  "#.#.........#.#".chars,
  "#.###########.#".chars,
  "#.............#".chars,
  "###############".chars,
]

puts s[r][c] == '.' ? "white" : "black"

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