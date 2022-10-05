#!/usr/bin/ruby
n = rand(5..8)
c = n.times.map{ rand(1..n) }
x = n.times.map{ rand(1..n) }
puts n
puts c.join(" ")
puts x.join(" ")