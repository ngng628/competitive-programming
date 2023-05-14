# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
s = str.chars

l, r, m = nil.as(Int32?), nil.as(Int32?), nil.as(Int32?)
s.each_with_index do |si, i|
  if si == '|'
    if l.nil?
      l = i
    else
      r = i
    end
  elsif si == '*'
    m = i
  end
end

puts (l.not_nil!..r.not_nil!).includes?(m.not_nil!) ? "in" : "out"
