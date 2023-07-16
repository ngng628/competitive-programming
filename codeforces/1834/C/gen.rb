n = rand(1..5)
puts 1
puts n
s = (0...n).map { ('a'.ord + rand(26)).chr }.join
t = (0...n).map { ('a'.ord + rand(26)).chr }.join
puts s
puts t