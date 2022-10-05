# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def query(a, b, c, d)
  puts "? #{a + 1} #{b} #{c + 1} #{d}"
  STDOUT.flush
  int
end

def answer(i, j)
  puts "! #{i + 1} #{j + 1}"
  STDOUT.flush
end

n = int
if n == 1
  answer(0, 0)
  exit
end

mode = true
i1, i2, j1, j2 = 0, n, 0, n
i, j = nil, nil
20.times do
  if mode
    t = query(i1, (i2 - i1) // 2 + i1, j1, j2)
    if t == (i2 - i1) // 2
      i1 = (i2 - i1) // 2 + i1
    else
      i2 = (i2 - i1) // 2 + i1
    end
  else
    t = query(i1, i2, j1, (j2 - j1) // 2 + j1)
    if t == (j2 - j1) // 2
      j1 = (j2 - j1) // 2 + j1
    else
      j2 = (j2 - j1) // 2 + j1
    end
  end

  if i2 - i1 == 1
    i = i1
    mode = false
    i1, i2 = 0, n
  end
  if j2 - j1 == 1
    j = j1
    break
  end
end

answer(i.not_nil!, j.not_nil!)