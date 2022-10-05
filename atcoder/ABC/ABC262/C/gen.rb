n = rand(1..5*10**5)
puts n
a = Array.new(n){ rand(1..) }
puts a.join(" ")