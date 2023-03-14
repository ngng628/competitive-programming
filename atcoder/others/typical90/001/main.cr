# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, l = ints
k = int
a = [0_i64] + ints + [l]
n += 1

pp! a

# 全ての羊羹の長さを len 以下にできますか？
ans = l - (0_i64..l).bsearch { |b|
  border = l - b
  left = 0
  cnt = 0
  res = nil
  while left < n
    right = left
    res = false if a[right + 1] - a[left] < border
    while right < n && a[right + 1] - a[left] <= border
      right += 1
    end
    if res
      next res
    end
    pp! left, right
    left = right
    cnt += 1
  end
  puts "#{border} : #{cnt}"
  cnt <= k + 1
}.not_nil!

puts ans
