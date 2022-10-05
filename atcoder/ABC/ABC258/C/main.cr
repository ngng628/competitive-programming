# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def int; gets.to_s.to_i64 end
def ints; gets.to_s.split.map(&.to_i64) end
def int(offset); gets.to_s.to_i64 - 1 end
def ints(offset); gets.to_s.split.map{ |x| x.to_i64 - offset} end
def str; gets.to_s.chomp.chars end
def min(a, b); a < b ? a : b end
def max(a, b); a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
def rng(a, b); (a...b).each{ |i| yield(i) } end
alias I32 = Int32
alias I64 = Int64
DYDX4 = [ {1, 0}, {-1, 0}, {0, 1}, {0, -1} ]
DYDX8 = [ {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} ]

# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, q = ints
s = str

cur = 0
q.times do
  t, x = ints
  if t == 1
    cur = ((cur - x) % n + n) % n
  else
    x -= 1
    puts s[(cur + x) % n]
  end
end
