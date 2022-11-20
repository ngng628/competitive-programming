# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, q = ints

sets = Hash(Int64, Set(Int64)).new
q.times do
  t, a, b = ints
  case t
  when 1
    sets[a] = Set(Int64).new unless sets.has_key?(a)
    sets[a] << b
  when 2
    next unless sets.has_key?(a)
    sets[a].delete(b)
  when 3
    sets[a] = Set(Int64).new unless sets.has_key?(a)
    sets[b] = Set(Int64).new unless sets.has_key?(b)
    ans = sets[a].includes?(b) && sets[b].includes?(a)
    puts ans ? "Yes" : "No"
  end
end