# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
def min(x : Int64, y : Int64) : Int64; x < y ? x : y end
def max(x : Int64, y : Int64) : Int64; x > y ? x : y end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, k = ints
a = ints

cache = Array.new(k + 1){ Array(Int32?).new(2){ nil } }
dp = uninitialized Proc(Int64, Int32, Int32)
dp = ->(n_stones : Int64, turn : Int32) do
  return turn if n_stones < 0
  return cache[n_stones][turn].not_nil! if cache[n_stones][turn]

  win = a.any?{ |x| dp.call(n_stones - x, turn ^ 1) == turn }

  res = win ? turn : turn ^ 1
  cache[n_stones][turn] = res
  res
end

puts dp.call(k, 0) == 0 ? "First" : "Second"