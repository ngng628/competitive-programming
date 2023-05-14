# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints

ans = String.build { |io|
  (n - 1).times do |i|
    if a[i] < a[i + 1]
      io << a[i].upto(a[i + 1] - 1).join(" ") << ' '
    else
      io << a[i].downto(a[i + 1] + 1).join(" ") << ' '
    end
  end
  io << a[-1]
}

puts ans
