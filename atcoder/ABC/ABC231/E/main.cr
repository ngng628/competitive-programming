# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, x = ints
a = ints

pays = Array.new(n){ 0_i64 }
y = x
(0...n).reverse_each do |i|
  pays[i] = y // a[i]
  y %= a[i]
end

cache = Array.new(n + 1){ [nil, nil] of Int64? } 
dp = uninitialized Proc(Int32, Int32, Int64)
dp = ->(i : Int32, c : Int32) do
  return c == 0 ? 0_i64 : OO if i == n
  return cache[i][c].not_nil! unless cache[i][c].nil?

  res = OO

  if i < n - 1
    payed = (a[i + 1] - a[i] * (pays[i] + c)) // a[i]
    res = Math.min(res, dp.call(i + 1, 1) + payed)
  end

  pay = pays[i] + c
  res = Math.min(res, dp.call(i + 1, 0) + pay)

  cache[i][c] = res
end

puts dp.call(0, 0)