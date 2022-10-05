h1, w1 = read_line.split.map(&.to_i)
a = (1..h1).map{ read_line.split.map{ |x| x.to_i || nil } }
h2, w2 = read_line.split.map(&.to_i)
b = (1..h2).map{ read_line.split.map(&.to_i) }

ans = (1 << h1).times.any? do |mask_h|
  aa = a.clone
  h1.times{ |i| w1.times{ |j| aa[i][j] = nil } if mask_h.bit(i).odd? }
  (1 << w1).times.any? do |mask_w|
    aaa = aa.clone
    w1.times{ |j| h1.times{ |i| aaa[i][j] = nil } if mask_w.bit(j).odd? }

    aaa = aaa.map(&.compact)
    aaa.delete([] of Int32)
    b == aaa
  end
end

puts ans ? "Yes" : "No"