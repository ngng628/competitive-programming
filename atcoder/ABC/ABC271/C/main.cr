# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints.tally

ans = 10**9 + 1 - (0..10**9 + 1).bsearch do |k|
  k = 10**9 + 1 - k

  rem = 0
  a.each do |(key, cnt)|
    if key <= k
      rem += cnt - 1
    else
      rem += cnt
    end
  end

  now = 0
  until now >= k
    if a.fetch(now.succ, 0) >= 1
      now += 1
    elsif rem >= 2
      now += 1
      rem -= 2
    else
      break
    end
  end

  now >= k
end.not_nil!

puts ans