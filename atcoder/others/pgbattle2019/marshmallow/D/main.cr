# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

struct Edge
  getter to : Int64
  getter weight : Int64
  getter cong : Int64  # 混雑度
  def initialize(@to : Int64, @weight : Int64, @cong : Int64); end
end
alias Edges = Array(Edge)
alias Graph = Array(Edges)

n, m, t, k = ints
graph = Graph.new(n){ Edges.new }
m.times do
  a, b, c, d = ints
  graph[a - 1] << Edge.new(b - 1, c, d)
  graph[b - 1] << Edge.new(a - 1, c, d)
end

dist = Array.new(graph.size){ OO }
heap = Heap({Int64, Int64}).min
dist[0] = 0_i64
heap << { dist[0], 0_i64 }
until heap.empty?
  d, now = heap.pop
  next if dist[now] < d
  graph[now].each do |edge|

    th = edge.cong - k + t
    # puts "(#{now + 1}) th = #{th}, #{d}, #{edge.weight}, #{edge.cong}"
    d2 = d + edge.weight
    # puts "#{edge.cong - (t - d).abs <= k} && #{edge.cong - (t - d2).abs <= k} && #{t - d2 >= 0}"
    cost = d + (if t - d >= 0
      if edge.cong - (t - d).abs <= k && edge.cong - (t - d2).abs <= k && t - d2 >= 0
        # puts "p1"
        0_i64
      else
        # puts "p2"
        Math.max(0_i64, th - d)
      end
    else
      # puts "p3"
      Math.max(0_i64, th - d)
    end) + edge.weight
    # pp! cost

    if dist[edge.to] > cost
      dist[edge.to] = cost
      heap << { cost, edge.to }
    end
  end
end

# pp! dist
puts dist[n - 1] >= OO ? -1 : dist[n - 1]


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