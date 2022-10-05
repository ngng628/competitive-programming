# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset); read_line.to_i64 - 1 end
def ints(offset); read_line.split.map{ |x| x.to_i64 - offset} end
def str; read_line.chomp end
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

n = int
a = (0...n).map{ read_line.split("").map(&.to_i64) }

ans = n.times.max_of do |si|
  n.times.max_of do |sj|
    DYDX8.max_of do |di, dj|
      i = si
      j = sj
      n.times.reduce("") do |acc, _|
        t = a[i][j]
        i = (((i + di) % n) + n) % n
        j = (((j + dj) % n) + n) % n
        acc + t.to_s
      end.to_i64
    end
  end
end

puts ans