# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, x = ints
graph = Graph.new(n){ Edges.new }
(n - 1).times do |i|
  a, b, c = ints
  a -= 1
  b -= 1
  graph[a] << Edge.new(b, c)
  graph[b] << Edge.new(a, c)
end

dists = Array.new(n){ Array.new(n){ OO } }
n.times do |s|
  heap = Heap({Int64, Int64}).min
  dists[s][s] = 0
  heap << { dists[s][s], s }
  until heap.empty?
    d, from = heap.pop
    next if dists[s][from] < d
    graph[from].each do |edge|
      cost = edge.weight
      if dists[s][edge.to] > dists[s][from] + cost
        dists[s][edge.to] = dists[s][from] + cost
        heap << { dists[s][edge.to], edge.to }
      end
    end
  end
end

n.times do |i|
  n.times.reject{ |j| i == j }.each do |j|
    if dists[i][j] == x
      puts "Yes"
      exit
    end
  end
end

puts "No"




struct Edge
  getter to : Int64
  getter weight : Int64
  def initialize(@to : Int64, @weight : Int64); end
end
alias Edges = Array(Edge)
alias Graph = Array(Edges)


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