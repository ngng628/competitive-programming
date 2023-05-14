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
b = ints

# if a.sort != b.sort
#   puts "No"
#   exit
# end

def calc_indices(v)
  indices = Array.new(v.size) { [] of Int64 }
  v.each_with_index do |vi, i|
    indices[vi - 1] << i + 1
  end
  indices
end

pp! calc_indices(a)
pp! calc_indices(b)

n.times do |i|
  next if a[i] == b[i]

end
