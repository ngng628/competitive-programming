# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m, k = ints
s = str.chars

csum = Array(Int64).new(n + 1)
csum << 0_i64
n.times do |i|
  csum << csum[-1] + (s[i] == 'x' ? 1 : 0)
end

query = ->(left : Int64, right : Int64) {
  return 0_i64 if left >= right
  return csum[right] - csum[left] if right <= n

  chmin(right, n * m)

  res = {
    csum[n] - csum[left],
    (right // n - 1)* csum[n],
    csum[right % n]
  }.sum

  res
}

ans = 0_i64
n.times do |left|
  ok = n * m
  ng = left

  if query.call(left, ok) <= k
    chmax(ans, (left...ok).size)
    next
  end

  preans = (ng..ok).bsearch { |right|
    num = query.call(left, right)
    num > k
  }.not_nil!

  chmax(ans, (left...preans).size - 1) if preans
end

puts ans
