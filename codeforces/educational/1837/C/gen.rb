cases = []
(3**4).times do |mask|
  s = []
  4.times do |i|
    state = (mask / (3**i)) % 3
    if state == 0
      s << '0'
    elsif state == 1
      s << '1'
    else
      s << '?'
    end
  end
  cases << s.join
end

puts cases.size
puts cases.join("\n")
