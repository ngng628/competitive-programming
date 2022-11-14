# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

x, y = ints
dx = x.divisors.size
dy = y.divisors.size
if dx == dy
  puts "Z"
elsif dx > dy
  puts "X"
else
  puts "Y"
end

struct Int
  def divisors
    lo = Array(Int64).new
    hi = Array(Int64).new
    i = 1_i64
    while i**2 <= self
      if self % i == 0
        j = self // i
        lo << i
        if i != j
          hi << j
        end
      end
      i += 1
    end
    lo + hi
  end
end