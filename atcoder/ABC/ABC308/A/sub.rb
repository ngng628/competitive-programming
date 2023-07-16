a = gets.split.map &:to_i
ok = a.each_with_index.all? { |ai, i|
  [
    ai <= a[[i + 1, a.size - 1].min],
    100 <= ai && ai <= 675,
    ai % 25 == 0
  ].all?
}

puts ok ? "Yes" : "No"