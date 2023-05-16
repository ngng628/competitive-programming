# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
require "big"
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
ans = Int64::MAX
(1..Math.min(n, Math.sqrt(m).to_i64 + 10)).each do |a|
  # a * b >= m
  b = BigInt.new(m + a - 1) // a
  if b.in?(1..n)
    chmin(ans, b * a)
  end
end

puts ans == Int64::MAX ? -1 : ans


















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
