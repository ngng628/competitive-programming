d = read_line.to_i
a = read_line.chomp.chars
b = read_line.chomp.chars
if a.size < b.size
  a, b = b, a
end
n = a.size
b = ['0'] * (a.size - b.size) + b

ans = [] of Char
carry = 0
(n - 1).downto(0) do |i|
  if a[i] == '.'
    ans << '.'
  else
    d = (a[i].ord - '0'.ord) + (b[i].ord - '0'.ord) + carry
    ans << (d % 10 + '0'.ord).chr
    carry = d // 10
  end
end

ans << (carry + '0'.ord).chr if carry > 0

puts ans.reverse.join
