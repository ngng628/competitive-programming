# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def greedy(s, n)
  ans = -1_i64
  (1 << s.size).times do |mask|
    t = s.clone
    s.size.times do |i|
      if (mask >> i).odd? && t[i] == '?'
        t[i] = '1'
      elsif (mask >> i).even? && t[i] == '?'
        t[i] = '0'
      end
    end

    chmax(ans, t.join.to_i64(2)) if t.join.to_i64(2) <= n
  end
  ans
end

def to_bits(n)
  res = [] of Char
  until n == 0
    res << ((n % 2) + '0'.ord).chr
    n //= 2
  end
  res.reverse
end

s = str.chars
n = int

# pp! greedy(s.clone, n)

bits = to_bits(n)

# pp! s, bits
if s.size < bits.size
  ans = s.map { |c| c == '?' ? '1' : c }.join.to_i64(2)

  if ans <= n
    puts ans
  else
    puts -1
  end
else
  offset = (s.size - bits.size).abs
  t = s.clone
  (0...offset).each do |i|
    if s[i] == '1'
      puts -1
      exit
    else
      t[i] = '0'
    end
  end

  # pp! s

  bits = (['0'] * offset) + bits

  small = false
  hatena = -1
  (offset...bits.size).each do |i|
    cpy = s[i]
    if s[i] == bits[i]
      # 何もしない
    elsif s[i] == '0' && bits[i] == '1'
      small = true
    elsif s[i] == '1' && bits[i] == '0' && !small
      if hatena == -1
        puts -1
        exit
      end
      t[hatena] = '0'
      (hatena + 1..i).each do |j|
        t[j] = '1' if s[j] == '?'
      end
      small = true
    elsif s[i] == '?'
      if small
        t[i] = '1'
      else
        t[i] = bits[i]
      end
    end

    hatena = i if cpy == '?' && bits[i] == '1'
    # pp! i
    # pp! s[i]
    # pp! hatena
  end


  ans = t.join.to_i64(2)
  if ans <= n
    # puts "t    # => #{t}"
    puts ans
  else
    if hatena != -1
      t[hatena] = '0'
    end
    ans = t.join.to_i64(2)
    if ans <= n
      puts ans
    else
      puts -1
    end
  end
end
