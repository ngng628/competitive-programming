# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
s = str

if s.count('T') > s.count('A')
  puts 'T'
elsif s.count('T') < s.count('A')
  puts 'A'
else
  sum = s.count('T')
  n.times do |i|
    if s[0..i].count('T') == sum
      puts 'T'
      break
    elsif s[0..i].count('A') == sum
      puts 'A'
      break
    end
  end
end
