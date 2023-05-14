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

ans = -1
rle = s.slice_when{ |i, j| i != j }.map{ |a| { a[0], a.size} }.to_a
rle.size.times do |i|
  if rle[i][0] == 'o'
    chmax(ans, rle[i][1]) if i >= 1 && rle[i - 1][0] == '-'
    chmax(ans, rle[i][1]) if i + 1 < rle.size && rle[i + 1][0] == '-'
  end
end

puts ans
