n = 100
q = 100
puts "#{n} #{q}"
q.times do
  l = rand(1..n)
  r = rand(1..n)
  while l <= r
    l = rand(1..n)
    r = rand(1..n)
  end
  puts "#{l} #{r}"
end