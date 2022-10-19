# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints

evens = a.select{ |ai| ai.even? }.sort
odds = a.select{ |ai| ai.odd? }.sort

ans = Math.max((evens[-1]? || -OO) + (evens[-2]? || -OO), (odds[-1]? || -OO) + (odds[-2]? || -OO))
puts evens[-2]?.nil? && odds[-2]?.nil? ? -1_i64 : ans