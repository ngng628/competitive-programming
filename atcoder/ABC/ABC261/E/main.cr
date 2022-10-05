# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
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
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．


n, c = ints
functions = Array(Hash(Int32, Int32)).new(30){ { 0 => 0, 1 => 1 } }

n.times do
  t, a = ints
  30.times do |i|
    b = ((a >> i) & 1).odd? ? 1 : 0
    f0 = functions[i][0]
    f1 = functions[i][1]
    case t
    when 1
      functions[i][0] = b & f0
      functions[i][1] = b & f1
    when 2
      functions[i][0] = b | f0
      functions[i][1] = b | f1
    when 3
      b = ((a >> i) & 1).odd? ? 1 : 0
      functions[i][0] = b ^ f0
      functions[i][1] = b ^ f1
    end
  end
  ans = 0
  30.times do |i|
    bit = functions[i][(c >> i) & 1]
    ans += (2**i) * bit 
  end
  c = ans

  puts ans
end
