n, q = gets.split.map(&:to_i)
a = (1..n).map{ gets.split.map(&:to_i) }
q.times do
  s, t = gets.split.map(&:to_i)
  puts a[s - 1][t]
end