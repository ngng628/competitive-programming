# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
def min(x : Int64, y : Int64) : Int64; x < y ? x : y end
def max(x : Int64, y : Int64) : Int64; x > y ? x : y end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
FIRST = 0
SECOND = 1
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints
dp = Array.new(n){ Array.new(n){ 0_i64 } }

cache = Array.new(n){ Array.new(n){ Array(Int64?).new(2){ nil } }}
rec = uninitialized Proc(Int32, Int32, Int32, Int64)
rec = ->(l : Int32, r : Int32, turn : Int32) do
  return 0_i64 if l > r
  return cache[l][r][turn].not_nil! if cache[l][r][turn]
  case turn
  when FIRST
    return cache[l][r][turn] = max(rec.call(l + 1, r, turn ^ 1) + a[l], rec.call(l, r - 1, turn ^ 1) + a[r])
  else
    return cache[l][r][turn] = min(rec.call(l + 1, r, turn ^ 1) - a[l], rec.call(l, r - 1, turn ^ 1) - a[r])
  end
end

puts rec.call(0, n.to_i - 1, 0)
