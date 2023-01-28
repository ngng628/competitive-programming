# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

s = str.chars
n = s.size

t = s.select{ |c| c != 'x' }

(puts -1) + exit if t != t.reverse

ans = 0
l = 0
r = n - 1
while l < r
  if s[l] == s[r]
    l += 1
    r -= 1
  elsif s[l] == 'x'
    l += 1
    ans += 1
  else
    r -= 1
    ans += 1
  end
end

puts ans