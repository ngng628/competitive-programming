# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, c = ints
hs = ints

dp = Array.new(n + 1){ 0_i64 }
cht = ConvexHullTrick(Int64).new 
cht.add(-2_i64 * hs[0], hs[0]**2 + dp[0])
hs.each_with_index do |h, i|
  dp[i + 1] = cht.min(h) + h**2 + c
  cht.add(-2_i64 * h, h**2 + dp[i + 1])
end
puts dp[n]

class ConvexHullTrick(T)
  getter lines : Array({T, T})
  @head : Int32

  def initialize
    @head = 0
    @lines = Array({T, T}).new
  end

  def add(k : T, b : T)
    line = {k, b}
    while @lines.size - @head >= 2 && check(@lines[-2], @lines.last, line)
      @lines.pop
    end
    @lines << line
  end

  def min(x : T)
    while @lines.size - @head >= 2 && @lines[@head][0] * x + @lines[@head][1] >= @lines[@head + 1][0] * x + @lines[@head + 1][1]
      @head += 1
    end
    @lines[@head][0] * x + @lines[@head][1]
  end

  private def check(l1 : {T, T}, l2 : {T, T}, l3 : {T, T})
    (l2[0] - l1[0]) * (l3[1] - l2[1]) >= (l2[1] - l1[1]) * (l3[0] - l2[0])
  end
end