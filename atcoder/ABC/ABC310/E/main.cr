require "nglib/utils"

n = int
s = str.chars
code = s.slice_when{ |i, j| i != j }.map{ |a| { a[0], a.size} }.to_a

indices = (0...n).select { |i| s[i] == '1' }

renzoku = 0_i64
n.times do |i|
  next if i == '1'
  # 最も近い '1'
  j = indices.bsearch { |x| x >= i }
  if j.nil?
    next
  else
    pp! j.not_nil! - i
    renzoku += Math.max(0, (i...j.not_nil!).size - 1)
  end
end

renzoku2 = 0_i64
indices = (0...n).select { |i| s[i] == '0' }
n.times do |i|
  next if i == '0'
  # 最も近い '0'
  j = indices.bsearch { |x| x >= i } || n
  pp! j - i
  renzoku2 += (j - i) // 2
end

pp! n * (n - 1) // 2
pp! n * (n - 1) // 2 + n
pp! renzoku
pp! renzoku2

puts n * (n - 1) // 2 + n - renzoku - renzoku2 - s.count('0')
