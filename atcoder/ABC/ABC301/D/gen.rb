len = 12
s = ""
len.times do
  s << "01?"[rand(0...3)]
end
n = rand(2**12)
puts s
puts n