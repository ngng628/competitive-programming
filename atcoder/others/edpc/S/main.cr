MOD = 10**9 + 7

k = read_line.chars.map(&.to_i)
d = read_line.to_i

less, equal = 0, 1
ans = k.reduce(Array.new(d){ |r| Array.new(2){ |ord| r == 0 && ord == equal ? 1 : 0 } }) do |dp, ki|
  dp2 = Array.new(d){ Array.new(2){ 0 } }
  d.times do |r|
    {less, equal}.each do |ord|
      (0..9).each do |x|
        r2 = (r + x) % d
        ord2 = ord

        next if ord == equal && x > ki
        ord2 = less if x < ki

        dp2[r2][ord2] = (dp2[r2][ord2] + dp[r][ord]) % MOD
      end
    end
  end
  dp2
end

puts ans[0].reduce(-1){ |memo, a| (memo + a) % MOD }