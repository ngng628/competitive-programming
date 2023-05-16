# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w = ints
s = (1..h).map { str.chars }

ans = String.build { |io|
  h.times do |i|
    j = 0
    while j < w - 1
      if s[i][j] == s[i][j + 1] && s[i][j + 1] == 'T'
        io << 'P' << 'C'
        j += 2
      else
        io << s[i][j]
        j += 1
      end
    end
    io << s[i].last if j == w - 1
    io << '\n'
  end
}

puts ans
