# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
a = ints








hash = Hash(Int64, Array(Int64)).new
a.each do |ai|
  hash[ai % m] = Array(Int64).new unless hash.has_key?(ai % m)
  hash[ai % m] << ai
end

hash.each_key do |key|
  hash[key].sort!
end
hash.each{ |key, value| puts "#{key} => #{value}" }

# とりあえず 0 から始めるとする
index = -OO
start = false
n.times do |i|
  if hash.has_key?(i % m) && !hash[i % m].empty?
    start = true
    t = hash[i % m].pop
    while !hash[i % m].empty? && t == hash[i % m][-1]
      hash[i % m].pop
    end
  elsif start
    index = i
    break
  end
end

hash.each{ |key, value| puts "#{key} => #{value}" }
puts "─" * 30

start = false
(0...n).reverse_each do |i|
  if hash.has_key?(i % m) && !hash[i % m].empty? && index <= i
    start = true
    t = hash[i % m].pop
    while !hash[i % m].empty? && t == hash[i % m][-1]
      hash[i % m].pop
    end
  elsif start
    break
  end
end


hash.each{ |key, value| puts "#{key} => #{value}" }
puts "─" * 30


puts hash.sum{ |_, v| v.sum }