OO = 1_001_001_001
alias Edges = Array({ Int32, Int32 })
alias Graph = Array(Edges)

n, m = read_line.split.map(&.to_i)
edges = Array(Array(Int32)).new(n){ Array(Int32).new(n, OO) }
m.times do |i|
  a, b, c = read_line.split.map(&.to_i)
  a -= 1
  b -= 1
  edges[a][b] = { edges[a][b], c }.min
end

graph = Graph.new(n){ Edges.new }
rev = Graph.new(n){ Edges.new }
me = Array.new(n, OO)
n.times do |i|
  n.times do |j|
    me[i] = edges[i][j] if i == j
    if edges[i][j] != OO
      graph[i] << { j, edges[i][j] }
      rev[j] << { i, edges[i][j] }
    end
  end
end

def dijkstra(s : Int32, graph : Graph)
  dist = Array.new(graph.size){ OO }
  heap = Heap({Int32, Int32}).min
  dist[s] = 0
  heap << { dist[s], s }
  until heap.empty?
    d, now = heap.pop
    next if dist[now] < d
    graph[now].each do |nxt, weight|
      cost = dist[now] + weight
      if dist[nxt] > cost
        dist[nxt] = cost
        heap << { cost, nxt }
      end
    end
  end
  dist
end

n.times.each do |s|
  fwd = dijkstra(s, graph)
  bwd = dijkstra(s, rev)
  d1 = n.times.reject{ |g| s == g }.min_of? do |g|
    fwd[g] + bwd[g]
  end || OO
  d2 = me[s]
  ans = {d1, d2}.min
  puts ans >= OO ? -1 : ans
end

class Heap(T)
  include Comparable(Heap(T))

  delegate size, to: hp
  delegate empty?, to: hp
  getter hp : Array(T)

  def <=>(other : Heap(T))
    @hp <=> other.hp
  end

  def self.min
    new { |a, b| a > b }
  end

  def self.max
    new { |a, b| a < b }
  end

  def initialize
    @cmp = ->(a : T, b : T) { a < b }
    @hp = Array(T).new
  end

  def initialize(&@cmp : (T, T) -> Bool)
    @hp = Array(T).new
  end

  def <<(value : T)
    push(value)
  end

  def push(value : T)
    @hp.push(value)
    child = @hp.size - 1
    v = @hp[child]
    while child > 0
      parent = (child - 1) // 2
      unless @cmp.call @hp[parent], v
        break
      end
      @hp.swap(parent, child)
      child = parent
    end
    @hp[child] = v
  end

  def pop
    len = @hp.size - 1
    if len > 0
      v = @hp[len]
      @hp[len] = @hp[0]
      parent = 0
      child = 1
      while child < len
        if child + 1 < len && @cmp.call @hp[child], @hp[child + 1]
          child += 1
        end
        unless @cmp.call v, @hp[child]
          break
        end
        @hp.swap(parent, child)
        parent = child
        child = 2*parent + 1
      end
      @hp[parent] = v
    end
    @hp.pop
  end

  def peek
    @hp.first
  end

  def clear
    @hp.clear
  end
end