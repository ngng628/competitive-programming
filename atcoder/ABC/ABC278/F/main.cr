# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
words = (1..n).map{ str.chars }

cache = Array.new(1 << n){ ([nil] of Bool?) * n }
dp = uninitialized Proc(Int32, Int32, Bool)
dp = ->(s : Int32, j : Int32) do
  return cache[s][j].not_nil! unless cache[s][j].nil?

  if s.popcount.even?
     res = false
     n.times.select{ |i| s.bit(i) == 0 }.each do |i|
        if words[j].last == words[i].first
           res |= dp.call(s | (1 << i), i)
        end
     end
     cache[s][j] = res
  else
     res = true
     n.times.select{ |i| s.bit(i) == 0 }.each do |i|
        if words[j].last == words[i].first
           res &= dp.call(s | (1 << i), i)
        end
     end
     cache[s][j] = res
  end

  cache[s][j].not_nil!
end

ans = n.times.any?{ |i| dp.call(1 << i, i) }

puts ans ? "First" : "Second"
