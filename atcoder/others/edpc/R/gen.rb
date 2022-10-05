#!/usr/bin/ruby
n = rand(1..10)
puts n
n.times do
  a = Array.new(n){ rand(-50..50) }
  puts a.join " "
end