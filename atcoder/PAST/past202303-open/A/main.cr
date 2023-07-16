n, s, t = read_line.split.map &.to_i
puts n.odd? ^ (s == 0) ^ (t == 0) ? "Alice" : "Bob"
