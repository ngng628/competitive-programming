def ok(seq, target)
  offset = 10**4
  dp = Array.new(seq.size + 1){ Array.new(10**5){ false } }
  dp[0][offset] = true
  seq.each_with_index do |ai, i|
    (ai..10**4 + offset).each do |k|
      dp[i + 1][k + ai] |= dp[i][k]
      dp[i + 1][k - ai] |= dp[i][k]
    end
  end
  dp[seq.size][target + offset]
end

n, gx, gy = read_line.split.map(&.to_i)
at = read_line.split.map(&.to_i)
a0 = at[0]
a = at[1..]
gx -= a0

xs = [] of Int32
ys = [] of Int32
a.each_with_index do |ai, i|
  if i.odd?
    xs << ai
  else
    ys << ai
  end
end

puts ok(xs, gx) && ok(ys, gy) ? "Yes" : "No"