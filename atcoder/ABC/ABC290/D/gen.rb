t = 10
puts t
t.times do
  n = rand(1..10**1)
  k = rand(1..n)
  d = rand(1..10**1)
  puts "#{n} #{d} #{k}"
end