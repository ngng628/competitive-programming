# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

alias Vi = Array(Int64)
alias Vvi = Array(Vi)
alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int64, b : Int64) : Int64; a < b ? a : b end
def max(a : Int64, b : Int64) : Int64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
          {-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]

# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
sx, sy, tx, ty = ints
points = Vvi.new(n){ ints }

def intersects(point : Vi, x : Int64, y : Int64)
  (x - point[0])**2 + (y - point[1])**2 == point[2]**2
end

start = -1_i64
graph = Vvi.new(n){ Vi.new }
points.each_with_index do |(x1, y1, r1), i|
  if intersects([x1, y1, r1], sx, sy)
    start = i.to_i64
  end
  points.each_with_index do |(x2, y2, r2), j|
    dx = x2 - x1
    dy = y2 - y1
    d = dx**2 + dy**2
    unless d > (r1 + r2)**2 || d < (r1 - r2)**2
      graph[i] << j.to_i64
    end
  end
end

que = Deque(Int64).new([start])
dist = Vi.new(n){ |i| i == start ? 0_i64 : OO }
until que.empty?
  now = que.shift
  graph[now].each do |nxt|
    next if dist[nxt] != OO
    dist[nxt] = dist[now] + 1
    que << nxt
  end
end

puts (0...n).select{ |i| dist[i] != OO && intersects(points[i], tx, ty) }.size > 0 ? "Yes" : "No"