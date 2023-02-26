# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
xy = (1..m).map { ints -1 }.uniq!

graph = Array.new(n) { [] of Int64 }
xy.each do |(x, y)|
  graph[x] << y
end

lengths = [OO] * n
dfs = uninitialized Int64 -> Int64
dfs = ->(from : Int64) do
  return lengths[from] if lengths[from] != OO
  lengths[from] = 0_i64
  graph[from].each do |to|
    chmax(lengths[from], dfs.call(to) + 1)
  end
  lengths[from]
end
n.times { |i| dfs.call(i) }
d = lengths.max

if d == n - 1
  order = topological_sort(graph)
  ans = [0_i64] * n
  cur = 0_i64
  order.each { |i| ans[i] = (cur += 1) }
  puts "Yes"
  puts ans.join(" ")
else
  puts "No"
end


def topological_sort(graph : Array(Array(Int64))) : Array(Int64)
  n = graph.size.to_i64
  res = Array(Int64).new(n)
  deg = [0] * n
  graph.each do |outs|
    outs.each do |to|
      deg[to] += 1
    end
  end

  que = Deque(Int64).new
  n.times do |i|
    que << i if deg[i] == 0
  end

  until que.empty?
    from = que.shift
    res << from
    graph[from].each do |to|
      deg[to] -= 1
      que << to if deg[to] == 0
    end
  end

  res
end
