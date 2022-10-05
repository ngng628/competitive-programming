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

n = int
a = ints


cache = Array.new(n + 1){ Array.new(n + 1){ Array(Float64 | Nil).new(n + 1){ nil } } }
dp = uninitialized Proc(Int32, Int32, Int32, Float64)
dp = ->(i : Int32, j : Int32, k : Int32) do
  return cache[i][j][k].not_nil! if cache[i][j][k]
  res = if i == 0 && j == 0 && k == 0
    0.0
  else
    tot = i + j + k
    s = 1.0 / (1.0 - (n - tot) / n)
    s += dp.call(i - 1, j, k) * i / n / (1.0 - (n - tot) / n) if i > 0
    s += dp.call(i + 1, j - 1, k) * j / n / (1.0 - (n - tot) / n) if j > 0
    s += dp.call(i, j + 1, k - 1) * k / n / (1.0 - (n - tot) / n) if k > 0
    s
  end
  cache[i][j][k] = res
  res
end

c = a.tally
ans = dp.call(c[1]? || 0, c[2]? || 0, c[3]? || 0)
puts printf("%.10f", ans)