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

s = str.chars.slice_when{ |i, j| i != j }.map{ |a| { a[0], a.size} }.to_a
t = str.chars.slice_when{ |i, j| i != j }.map{ |a| { a[0], a.size} }.to_a

l = (0_i64...min(s.size.to_i64, t.size.to_i64)).select{ |i| s[i][0] == t[i][0] }.size

if l != s.size || l != t.size
  puts "No"
else
  (0...s.size).each do |i|
    if s[i][1] > t[i][1]
      puts "No"
      exit
    elsif s[i][1] == t[i][1]
      next
    else
      if s[i][1] < 2
        puts "No"
        exit
      else
        next
      end
    end
  end
  puts "Yes"
end
