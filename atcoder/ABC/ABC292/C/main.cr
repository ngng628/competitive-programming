# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int

divs = [0_i64] * (n + 1)
(1_i64..n).each do |x|
  divs[x] = x.divisors.size.to_i64
end

ans = 0_i64
(1_i64..n).each do |a|
  (a..n).each do |b|
    break if a*b > n
    cd = n - a * b

    ans += divs[cd]
    ans += divs[cd] if a != b
  end
end

puts ans

struct Int
  def divisors
    lo = Array(Int64).new
    hi = Array(Int64).new
    i = 1_i64
    while i**2 <= self
      if self % i == 0
        j = self // i
        lo << i
        if i != j
          hi << j
        end
      end
      i += 1
    end
    lo + hi
  end
end
