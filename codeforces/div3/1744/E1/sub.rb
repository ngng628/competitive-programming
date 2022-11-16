def solve
  a, b, c, d = gets.split.map(&:to_i)
  ab = a * b
  
  diva = a.divisors
  divb = b.divisors
  
  ans = [-1, -1]
  diva.product(divb) do |(u, v)|
    s = u * v
    t = a * b / s
  
    x = (a + 1).div_ceil(s) * s
    y = (b + 1).div_ceil(t) * t
  
    if a < x && x <= c && b < y && y <= d
      ans = [x, y]
      break
    end
  end
  
  ans.join(" ")
end

class Integer
  def div_ceil(y); (self + y - 1) / y end
  def each_divisor; return Enumerator.new { |y| each_divisor { |k| y << k } } unless block_given?; k = 1; while k * k < self; if self % k == 0; yield k; yield self / k end; k += 1; end; yield k if k * k == self end
  def divisors; each_divisor.to_a end
end

ts = gets.to_i
ans = ""
while ts != 0
  ans << solve << "\n"
  ts -= 1
end
puts ans