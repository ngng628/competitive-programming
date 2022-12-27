n = gets.to_i
a = gets.split.map(&:to_i)

min, max = a.minmax
a.each do |ai|
  puts [(ai - min).abs, (ai - max).abs].max
end