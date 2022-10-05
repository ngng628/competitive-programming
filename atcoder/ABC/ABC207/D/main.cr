# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
alias Ai = Array(Int64)
alias Aai = Array(Ai)
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
macro len(v); v.size.to_i64 end
OO = (1_i64<<62)-(1_i64<<31)
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
          {-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]
def eq(a, b); (a - b).abs <= 1e-8 end
require "complex"
alias C = Complex
struct C
  def <=>(other : self)
    if eq(@real, other.real)
      @imag <=> other.imag
    else
      @real <=> other.real
    end
  end
end
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
if n == 1
  puts "Yes"
  exit
end
a = [0_i64] * n
b = [0_i64] * n
c = [0_i64] * n
d = [0_i64] * n
n.times{ |i| a[i], b[i] = ints }
n.times{ |i| c[i], d[i] = ints }

s = Array.new(n){ |i| C.new(a[i], b[i]) }
t = Array.new(n){ |i| C.new(c[i], d[i]) }


ans = (0...n).any? do |i|
  (0...n).reject{ |j| i == j }.any? do |j|
    c1 = s[1] - s[0]
    c2 = t[j] - t[i]
    theta = c2.phase - c1.phase
    rot = C.new(Math.cos(theta), Math.sin(theta))
    s2 = s.map{ |si| (si - s[0]) * rot }.sort.to_a
    t2 = t.map{ |ti| ti - t[i] }.sort.to_a
    (0...n).all? do |i|
      eq(s2[i].real, t2[i].real) && eq(s2[i].imag, t2[i].imag)
    end
  end
end

puts ans ? "Yes" : "No"