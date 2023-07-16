t = 1
n = 6
puts t
puts n
alphas = ('a'..'h').to_a
puts Array.new(n) {alphas[rand(0...alphas.size)]}.join