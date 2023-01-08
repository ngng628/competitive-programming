# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int

table = Array(Array({Int64, Int64})).new
length = 1_i64
while length <= n
  tab = [] of {Int64, Int64}
  left = 1_i64
  while left + length - 1 <= n
    right = left + length - 1
    tab << {left, right}
    left += 1
  end
  table << tab

  length *= 2
end

puts table.sum{ |ary| ary.size }
STDOUT.flush
indices = Hash({Int64, Int64}, Int64).new
index = 1_i64
table.each do |ary|
  ary.each do |(l, r)|
    indices[{l, r}] = index
    index += 1
    puts "#{l} #{r}"
    STDOUT.flush
  end
end

q = int
q.times do
  l, r = ints
  size = (1_i64 << (63 - (r - l + 1).leading_zeros_count))
  i = indices[{l, l + size - 1}]
  j = indices[{r - size + 1, r}]
  puts "#{i} #{j}"
  STDOUT.flush
end