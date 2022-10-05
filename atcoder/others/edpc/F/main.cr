s = ("*" + read_line.chomp).chars
t = ("*" + read_line.chomp).chars
n = s.size - 1
m = t.size - 1

macro update(i1, j1, i2, j2, added)
  if dp[{{ i1 }}][{{ j1 }}] < dp[{{ i2 }}][{{ j2 }}] + {{ added }}
    dp[{{ i1 }}][{{ j1 }}] = dp[{{ i2 }}][{{ j2 }}] + {{ added }}
    route[{{ i1 }}][{{ j1 }}] = { {{ i2 }}, {{ j2 }} }
  end
end

dp = Array.new(n + 1) { Array.new(m + 1) { 0 } }
route = Array.new(n + 1) { Array.new(m + 1) { {0, 0} } }
(1..n).each do |i|
  (1..m).each do |j|
    update(i, j, i - 1, j, 0)
    update(i, j, i, j - 1, 0)
    if s[i] == t[j]
      update(i, j, i - 1, j - 1, 1)
    end
  end
end


ans = [] of Char
i, j = n, m
until i == 0 || j == 0
  now = dp[i][j]
  i2, j2 = route[i][j]
  nxt = dp[i2][j2]
  if s[i] == t[j] && now > nxt
    ans << s[i]
  end
  i, j = route[i][j]
end

puts ans.reverse.join