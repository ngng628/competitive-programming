# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints.sort.reverse
b = ints.sort.reverse
c = ints.sort.reverse
d = ints.sort.reverse

abcd = a + b + c + d

ans = OO
abcd.each do |m|
  h1 = a.bsearch{ |ai| ai <= m }
  h2 = b.bsearch{ |bi| bi <= m }
  h3 = c.bsearch{ |ci| ci <= m }
  h4 = d.bsearch{ |di| di <= m }

  h = [h1, h2, h3, h4].reject(&.nil?).map(&.not_nil!).sort

  next if h.size < 4
  chmin(ans, h[-1] - h[0])
end

puts ans