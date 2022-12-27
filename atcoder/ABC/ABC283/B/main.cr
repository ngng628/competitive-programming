# 🎂🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁🎂
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# 🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄

n = int
a = ints
q = int
q.times do
  query = ints
  case query[0]
  when 1
    a[query[1] - 1] = query[2]
  when 2
    puts a[query[1] - 1]
  end
end