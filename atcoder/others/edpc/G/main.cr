# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
def min(x : Int64, y : Int64) : Int64; x < y ? x : y end
def max(x : Int64, y : Int64) : Int64; x > y ? x : y end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
graph = Array.new(n){ Array(Int64).new }
m.times do
  x, y = ints -1
  graph[x] << y
end

cache = Array.new(n){ 0_i64 }
hit = Array.new(n){ false }
closed = Array.new(n){ false }
n.times do |s|
  dfs = uninitialized Proc(Int64, Int64)
  dfs = ->(from : Int64) do
    return cache[from] if hit[from]
    mx = graph[from].max_of? do |to|
      dfs.call(to)
    end || -1_i64
    hit[from] = true
    cache[from] = mx + 1
  end
  closed[s] = true
  dfs.call(s)
end

puts cache.max? || 0_i64