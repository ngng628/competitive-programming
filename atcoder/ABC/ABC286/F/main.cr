# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i32 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i32 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 1. 適当な m, a を決定
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
primes = [4, 9, 5, 7, 11, 13, 17, 19, 23]
acc = 0
a = primes.map { |pr|
  b = (0...pr).map(&.+(acc))
  b = b[1..] + [b[0]]
  acc += pr
  b
}.flatten
m = a.size

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 2. ジャッジに送信
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
puts m
STDOUT.flush
puts a.map(&.succ).join(" ")
STDOUT.flush

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 2. ジャッジから B を受信
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
b = ints -1

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 3. 中国剰余定理で答えを求める
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
rems = [] of Int32
mods = [] of Int32
acc = 0
primes.each do |pr|
  rems << b[acc] - acc + 1
  mods << pr
  acc += pr
end

r, m = Math.crt(rems.map(&.to_i64), mods.map(&.to_i64))

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# 4. 答えを出力
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
puts r - 1
STDOUT.flush

module Math
  def crt(rems : Array(Int64), mods : Array(Int64))
    r0 = 0_i64
    m0 = 1_i64
    rems.zip(mods).each do |(r1, m1)|
      r1 %= m1

      if m0 < m1
        r0, r1 = r1, r0
        m0, m1 = m1, m0
      end

      if m0 % m1 == 0
        return {0_i64, 0_i64} if r0 % m1 != r1
        next
      end

      g, im = inv_gcd(m0, m1)

      u1 = m1 // g
      return {0_i64, 0_i64} if (r1 - r0) % g != 0

      x = (r1 - r0) // g % u1 * im % u1
      r0 += x * m0
      m0 *= u1
      r0 += m0 if r0 < 0
    end

    {r0, m0}
  end

  def inv_gcd(a : Int64, b : Int64)
    a %= b
    return {b, 0} if a == 0

    s, t = b, a
    m0, m1 = 0_i64, 1_i64

    until t == 0
      u = s // t
      s -= t * u
      m0 -= m1 * u
      s, t = t, s
      m0, m1 = m1, m0
    end

    m0 += b // s if m0 < 0
    {s, m0}
  end
end