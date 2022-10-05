a = [1, 2, 3]
puts a
sum = a.reject{ |x| x > 0 }.min_of? do |x|
  x
end || Int32::MAX
puts sum