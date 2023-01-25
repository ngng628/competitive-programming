
module Math
  def crt(rems : Array(Int64), mods : Array(Int64))
    n = rems.size
    
    r0 = 0_i64
    m0 = 1_i64
    n.times do |i|
      r1 = rems[i] % mods[i]
      m1 = mods[i]

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


r, m = Math.crt([2_i64, 3_i64, 4_i64], [3_i64, 5_i64, 11_i64])
pp! r, m

k = (500 - r) // m
puts r + k*m
# if (500 - k*r + m).abs < (500 - )

