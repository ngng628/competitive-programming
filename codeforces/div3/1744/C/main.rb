ts = gets.to_i
ts.times do
  c = gets.split[1]
  s = gets.chomp
  ans = (s + s).split("g").map{ |t| t.size - (t.index(c) || 10**9) }.max
  puts c == "g" ? 0 : ans
end