# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w = ints
a = (1..h).map { str.chomp.chars }
b = (1..h).map { str.chomp.chars }

h.times do |si|
  w.times do |sj|
    c = Array.new(h) { |i|
      Array.new(w) { |j|
        a[(i + si) % h][(j + sj) % w]
      }
    }

    if b == c
      puts "Yes"
      exit
    end
  end
end

puts "No"
