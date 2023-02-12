# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
s = (1..m).map { c = int; Set.new(ints(-1)) }

ans = (1 << m).times.count { |mask|
  sets = Array(Set(Int64)).new
  m.times do |i|
    sets << s[i] if mask.bit(i) == 1
  end

  n.times.all? { |x|
    sets.any?(&.includes?(x))
  }
}

puts ans
