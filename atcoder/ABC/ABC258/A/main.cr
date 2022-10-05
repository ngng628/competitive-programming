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
def rep(n); n.times{ |i| yield(i) } end
def rep(a, b); (a...b).each{ |i| yield(i) } end
def reps(n); n.times{ |i| yield(i + 1) } end
def reps(a, b); (a..b).each{ |i| yield(i) } end
alias I32 = Int32
alias I64 = Int64

# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

k = int
puts sprintf("%02d:%02d", 21 + k // 60, k % 60)