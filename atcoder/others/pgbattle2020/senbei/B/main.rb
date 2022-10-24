n = gets.to_i
b = 5**n

ans = "0."
t = 10
until t == 0
  q = t / b
  r = t % b
  
  ans << q.to_s
  t = 10*r
end

puts ans