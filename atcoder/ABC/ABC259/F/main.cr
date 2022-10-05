# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int64, b : Int64) : Int64; a < b ? a : b end
def max(a : Int64, b : Int64) : Int64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
          {-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]

# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

