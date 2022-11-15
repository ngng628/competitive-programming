# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints -1
b = ints -1
g = Array.new(n){ Array(Int64).new }
h = Array.new(n){ Array(Int64).new }
(n - 1).times do |i|
  g[a[i]] << i
  h[b[i]] << i
end

cache = Array(Int64?).new(n){ nil }
dp = uninitialized Proc(Int64, Int64)
dp = ->(now : Int64) do
  return 0_i64 if now == 0
  return cache[now].not_nil! unless cache[now].nil?

  res = g[now].max_of?{ |to| dp.call(to) + 100 } || -OO
  chmax(res, h[now].max_of?{ |to| dp.call(to) + 150 } || -OO)

  cache[now] = res
end

puts dp.call(n - 1)