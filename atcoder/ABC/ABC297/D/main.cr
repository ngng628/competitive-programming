# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

a, b = ints
a, b = Math.min(a, b), Math.max(a, b)
cnt = 0_i64
if b % a == 0
  cnt += b // a - 1
  a = b
end

until a == b
  cnt += b // a
  b = b - (b // a) * a
  a, b = Math.min(a, b), Math.max(a, b)
  if b % a == 0
    cnt += b // a - 1
    a = b
  end
end

puts cnt
