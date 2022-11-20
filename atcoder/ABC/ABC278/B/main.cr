# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, m = str.split
h = "0" + h if h.size == 1
m = "0" + m if m.size == 1

def hoge(h : Array(Char), m : Array(Char))
  h2 = [h[0], m[0]]
  m2 = [h[1], m[1]]
  h3 = h2.join("").to_i
  m3 = m2.join("").to_i
  0 <= h3 && h3 <= 23 && 0 <= m3 && m3 <= 59
end

while true
  if hoge(h.chars, m.chars)
    puts "#{h} #{m}"
    exit
  end
  m = sprintf( "%02d", m.to_i + 1 )
  if m == "60"
    m = "00"
    h = sprintf( "%02d", h.to_i + 1 )
    if h == "24"
      h = "00"
    end
  end
end