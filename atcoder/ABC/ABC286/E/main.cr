# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

record Weight, n_chocos : Int64, value : Int64 do
  include Comparable(Weight)

  def self.zero
    Weight.new(0_i64, 0_i64)
  end

  def self.inf
    Weight.new(OO, -OO)
  end

  def inf?
    n_chocos >= OO && value <= -OO
  end

  def +(other : self)
    Weight.new(@n_chocos + other.n_chocos, @value + other.value)
  end

  def <=>(other : self)
    {@n_chocos, -@value} <=> {other.n_chocos, -other.value}
  end
end

n = int
a = ints
s = (1..n).map{ str.chars.map(&.==('Y')) }

dist = Array.new(n){ [Weight.inf] * n }
n.times do |i|
  n.times do |j|
    next unless s[i][j]
    dist[i][j] = Weight.new(1_i64, a[j])
  end
end

n.times do |via|
  n.times do |from|
    n.times do |to|
      chmin(dist[from][to], dist[from][via] + dist[via][to])
    end
  end
end

q = int
q.times do
  u, v = ints -1
  if dist[u][v].inf?
    puts "Impossible"
  else
    c = dist[u][v].n_chocos
    v = dist[u][v].value + a[u]
    puts "#{c} #{v}"
  end
end