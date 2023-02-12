# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
b = ints.sort.reverse!
c = ints

cht = ConvexHullTrick(Int64).max
b.each_with_index(1_i64) do |bi, i|
  cht.add(i, i*bi)
end

ans = c.map { |ci| cht.query(ci) }
puts ans.join(" ")







class ConvexHullTrick(T)
  getter lines : Array({T, T})
  @head : Int32
  @comp : T, T -> Bool

  def initialize(&@comp : T, T -> Bool)
    @head = 0
    @lines = [] of {T, T}
  end

  def self.min
    new { |lhs, rhs| lhs >= rhs }
  end

  def self.max
    new { |lhs, rhs| lhs <= rhs }
  end

  def add(k : T, b : T)
    line = {k, b}
    while @lines.size - @head >= 2 && check(@lines[-2], @lines.last, line)
      @lines.pop
    end
    @lines << line
  end

  def monotonic_query(x : T)
    while @lines.size - @head >= 2 && compare(f(@lines[@head], x), f(@lines[@head + 1], x))
      @head += 1
    end
    f(@lines[@head], x)
  end

  def query(x : T)
    ac = @lines.size - 1
    wa = -1
    while ac - wa > 1
      wj = (ac + wa) // 2
      if !compare(f(@lines[wj], x), f(@lines[wj + 1], x))
        ac = wj
      else
        wa = wj
      end
    end
    f(@lines[ac], x)
  end

  @[AlwaysInline]
  private def compare(a : T, b : T) : Bool
    @comp.call(a, b)
  end

  @[AlwaysInline]
  private def f(line : {T, T}, x) : T
    line[0] * x + line[1]
  end

  @[AlwaysInline]
  private def check(l1 : {T, T}, l2 : {T, T}, l3 : {T, T}) : Bool
    (l2[0] - l1[0]) * (l3[1] - l2[1]) >= (l2[1] - l1[1]) * (l3[0] - l2[0])
  end
end
