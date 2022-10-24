# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, k = ints
a = ints
graph = Array.new(n){ Array(Int64).new }
(n - 1).times do
  a, b = ints -1
  graph[a] << b
  graph[b] << a
end

def greedy(n, k, a, graph)
  n.times do |c|
    n.times do |u|
      (0...u).each do |v|
        
      end
    end
  end
end

puts greedy(n, k, a.dup, graph.dup)