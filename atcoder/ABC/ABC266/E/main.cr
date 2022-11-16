# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int

cache = Array(Float64?).new(n + 1){ nil }
dp = uninitialized Proc(Int64, Float64)
dp = ->(i : Int64) do
  return 0.0 if i == 0
  return cache[i].not_nil! unless cache[i].nil?

  cache[i] = (1..6).sum do |j|
    Math.max(dp.call(i - 1), j.to_f64) / 6.0
  end

  cache[i].not_nil!
end

puts dp.call(n)