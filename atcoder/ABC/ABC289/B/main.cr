# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
a = ints(-1).slice_when { |i, j| j - i > 1 }.to_a

ans = (1..n).to_a
a.each do |ai|
  l = ai[0]
  r = ai[-1] + 2
  n = r - l
  (n // 2).times do |i|
    ans.swap(l + i, r - i - 1)
  end
end

puts ans.join(" ")
