# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
macro make_array(s, x)
  Array.new({{ s[0] }}){
    {% if s[1..s.size].empty? %}; {{ x }}
    {% else %}; make_array({{ s[1..s.size] }}, {{ x }}) {% end %}
  }
end
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

#────────────────────────────────────────────────
# データ型
#────────────────────────────────────────────────
record Edge, to : Int64, weight : Int64
record Node, index : Int64, temp : Int32, ela : Int64

#────────────────────────────────────────────────
# 入力
#────────────────────────────────────────────────
n, m, x = ints
t = (1..n).map{ int.to_i32 }
graph = Array.new(n){ Array(Edge).new }
m.times do
  u, v, w = ints
  u -= 1; v -= 1
  graph[u] << Edge.new(v, w)
  graph[v] << Edge.new(u, w)
end

#────────────────────────────────────────────────
# ダイクストラ法
#────────────────────────────────────────────────
dist = make_array([n, 3, 200 + 1], OO)
dist[0][t[0]][0] = 0
heap = Heap({Int64, Node}).new{ |a, b| a[0] > b[0] }
heap << {0_i64, Node.new(0_i64, t[0], t[0] == 1 ? x : 0_i64)}
until heap.empty?
  d, now = heap.pop

  now_dist = dist[now.index][now.temp][now.ela]
  next if now_dist < d

  graph[now.index].each do |e|
    w = e.weight
    to = e.to

    cost = (t[to] - now.temp).abs == 2 && now.ela + w < x ? OO : w

    next_cost = now_dist + cost

    next_t = t[to] == 1 ? now.temp : t[to]

    next_ela = case t[to]
      when 0, 2
        0_i64
      else
        Math.min(now.ela + w, x)
    end

    if next_cost < dist[to][next_t][next_ela]
      dist[to][next_t][next_ela] = next_cost
      heap << {next_cost, Node.new(to, next_t, next_ela)}
    end
  end
end

ans = OO
chmin(ans, dist[n - 1][0].min)
chmin(ans, dist[n - 1][1].min)
chmin(ans, dist[n - 1][2].min)
puts ans







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