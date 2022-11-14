# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
s = str.chars

buff = Deque.new((0_i64...n).select{ |i| s[i] == '0' }.to_a)

a = Array(Int64).new(n){ OO }
n.times do |i|
  if s[i] == '1'
    a[i] = i
  else
    if buff.empty?
      next
    elsif buff[0] != i
      a[i] = buff[0]
      buff.shift
    elsif buff.size >= 2
      a[i] = buff[1]
      t = buff.shift
      buff.shift
      buff << t
    else
      next
    end
  end
end

if a.sort == (0_i64...n).to_a
  puts a.map{ |v| v + 1 }.join(" ")
else
  puts "-1"
end