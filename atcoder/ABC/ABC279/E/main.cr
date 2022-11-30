# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
a = ints -1

w = isqrt(m)
perms = Array.new(m.divceil(w)) {|i|
  l = i * w
  r = Math.min((i + 1) * w, m)

  perm = (0...n).to_a
  (l...r).each do |j|
    perm.swap(a[j], a[j] + 1)
  end

  rev = [-1] * n
  n.times do |j|
    rev[perm[j]] = j
  end
  rev
}

m.times do |i|
  cur = 0
  perms.each_with_index do |perm, j|
    l = j * w
    r = Math.min((j + 1) * w, m)

    if i.in?(l...r)
      (l...r).each do |k|
        next if k == i
        if a[k] == cur
          cur += 1
        elsif a[k] + 1 == cur
          cur -= 1
        end
      end
    else
      cur = perm[cur]
    end
  end

  puts cur + 1
end



struct Int
  def divceil(d : Int)
    (self + d - 1) // d
  end
end

def isqrt(n : Int)
  return n if n < 2
  res = n.class.zero
  bit = res.succ << (res.leading_zeros_count - 2)
  bit >>= n.leading_zeros_count & ~0x3
  while (bit != 0)
    if n >= res + bit
      n -= res + bit
      res = (res >> 1) + bit
    else
      res >>= 1
    end
    bit >>= 2
  end
  res
end