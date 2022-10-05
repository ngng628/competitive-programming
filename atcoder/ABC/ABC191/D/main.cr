# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
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
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
{-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def binary_search(ac : Int64, wa : Int64, f : Proc(Int64, Bool))
  while (ac - wa).abs > 1
    wj = (ac + wa) >> 1
    if f.call(wj); ac = wj
    else; wa = wj end
  end
  ac
end

OO = 2_i64 * 10**9
K = 10_i64**4
ka, kb, kr = read_line.split.map{ |t| (t.to_f64 * K.to_f64).round.to_i64 }

ans = (-2*10**5..2*10**5).map{ |s| K*s }.sum do |ks|
  intersects = ->(y : Int64) { (ks - ka)**2 + (K*y - kb)**2 <= kr**2 }
  # y軸正方向の境界
  ok = (-1..1).max_of do |delta|
    b = kb // K
    intersects.call(b + delta) ? b + delta : -OO
  end
  ng = 2_i64 * 10**5 + 1
  next 0_i64 if ok == -OO
  y_pos = binary_search(ok, ng, intersects)

  # 負方向の境界
  ok = (-1..1).min_of do |delta|
    b = kb // K
    intersects.call(b + delta) ? b + delta : OO
  end
  ng = -(2_i64 * 10**5 + 1)
  next 0_i64 if ok == OO
  y_neg = binary_search(ok, ng, intersects)
  
  (y_pos - y_neg).abs + 1
end

puts ans