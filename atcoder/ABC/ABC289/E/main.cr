# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

class UndirectedGraph
  @size : Int32
  @graph : Array(Array(Int32))

  def initialize(n : Int)
    @size = n.to_i32
    @graph = Array.new(n) { [] of Int32 }
  end

  def add_edge(u : Int, v : Int)
    @graph[u] << v.to_i32
    @graph[v] << u.to_i32
  end

  def each_neighbor(v : Int, &block : Int32 ->)
    @graph[v].each { |u| block.call(u) }
  end
end

main = -> {
  n, m = ints
  c = ints
  graph = UndirectedGraph.new(n)
  m.times do
    u, v = ints -1
    graph.add_edge(u, v)
  end

  que = Deque({Int32, Int32}).new [{0, n.to_i32 - 1}]
  dist = Array.new(n) { Array.new(n){ OO } }
  dist[0][n - 1] = 0
  until que.empty?
    from = que.shift
    taka, aoki = from
    graph.each_neighbor(taka) do |taka_to|
      graph.each_neighbor(aoki) do |aoki_to|
        next if dist[taka_to][aoki_to] != OO
        next if c[taka_to] == c[aoki_to]
        dist[taka_to][aoki_to] = dist[taka][aoki] + 1
        que << {taka_to, aoki_to}
      end
    end
  end

  ans = dist[n - 1][0]
  puts ans >= OO ? -1 : ans
}

t = int
t.times { main.call }
