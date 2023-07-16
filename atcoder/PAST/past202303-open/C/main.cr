n = read_line.to_i
a = read_line.split.map &.to_i
puts (1..n).map { |k| a.index(k).not_nil! + 1 }.join(" ")