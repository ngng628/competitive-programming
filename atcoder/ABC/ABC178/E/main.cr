n = read_line.to_i64
pos = n.times.map{ read_line.split.map(&.to_i64) }.map{ |(x, y)| {x - y, x + y} }.to_a
u = pos.map{ |uu, vv| uu }
v = pos.map{ |uu, vv| vv }
ans = { (u.max - u.min).abs, (v.max - v.min).abs }.max
puts ans