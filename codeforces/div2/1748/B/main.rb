# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); gets.to_i + b end
def ints(b = 0); gets.split.map{ |x| x.to_i + b } end
def str; gets.chomp end
OO = (1<<62)-(1<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def solve
  n = int
  s = str.chars.map(&:to_i)

  cnt = Array.new(10){ Array.new(n + 1){ 0 } }
  (0..9).each do |d|
    exist = s.map{ |x| x == d ? 1 : 0 }
    n.times do |i|
      cnt[d][i + 1] = cnt[d][i] + exist[i]
    end
  end

  n.times.sum do |left|
    (left + 1..[left + 1 + 11, n].min).count do |right|
      k = (0..9).count{ |d| cnt[d][right] - cnt[d][left] > 0 }
      (0..9).all?{ |d| cnt[d][right] - cnt[d][left] <= k }
    end
  end
end

t = int
t.times do
  ans = solve
  puts ans
end