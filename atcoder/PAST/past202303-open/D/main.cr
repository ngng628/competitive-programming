h, a, b, c, d = read_line.split.map &.to_i64

ans = (0..40).min_of { |nd|
  h0 = h
  cost = 0_i64
  nd.times do
    h0 -= c
    if h0 > 1
      h0 //= 2
    end
    cost += d
  end
  cost += ((Math.max(0_i64, h0) + a - 1) // a) * b
  cost
}

puts ans
