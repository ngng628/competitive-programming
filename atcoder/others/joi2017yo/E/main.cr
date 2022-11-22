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

nd = ->(y : Int64, x : Int64){ w * y + x }

graph = Array.new(h * w){ Array(Int64).new }
h.times do |i|
  w.times do |j|
    graph[nd.call(i + 1, j)] << nd.call(i, j) if i + 1 < h && a[i][j] > a[i + 1][j]
    graph[nd.call(i - 1, j)] << nd.call(i, j) if i - 1 >= 0 && a[i][j] > a[i - 1][j]
    graph[nd.call(i, j + 1)] << nd.call(i, j) if j + 1 < w && a[i][j] > a[i][j + 1]
    graph[nd.call(i, j - 1)] << nd.call(i, j) if j - 1 >= 0 && a[i][j] > a[i][j - 1]
  end
end

stops = Array(Int64).new
h.times do |i|
  w.times do |j|
    cnt = [i + 1 < h, i - 1 >= 0, j + 1 < w, j - 1 >= 0].count{ |v| v }
    stops << nd.call(i, j) if graph[nd.call(i, j)].size == cnt
  end
end

tops = Array.new(h * w){ 0_i64 }
closed = Array.new(h * w){ false }
stops.each do |s|
  dfs = uninitialized Proc(Int64, Nil)
  dfs = ->(from : Int64) do
    graph[from].each do |to|
      next if closed[to]
      closed[to] = true
      dfs.call(to)
    end
    tops[from] += 1 if s != from
    nil
  end
  dfs.call(s)
end

ans = tops.count{ |c| c >= 2 }
puts ans