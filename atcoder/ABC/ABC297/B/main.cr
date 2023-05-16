# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

s = str.chars
n = s.size

n.times do |i|
  n.times do |j|
    next if i == j
    if s[i] == s[j] && s[j] == 'B'
      unless (i + j).odd?
        puts "No"
        exit
      end
    end
  end
end

n.times do |i|
  (i + 1...n).each do |j|
    n.times do |k|
      if s[i] == 'R' && s[j] == 'R' && s[k] == 'K'
        unless i < k && k < j
          puts "No"
          exit
        end
      end
    end
  end
end

puts "Yes"
