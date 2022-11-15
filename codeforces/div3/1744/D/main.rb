def max(a, b)
  a < b ? b : a
end

def log2(n)
  cnt = 0
  while n % 2 == 0
    n /= 2
    cnt += 1
  end
  cnt
end

ts = gets.to_i
ts.times do
  n = gets.to_i
  a = gets.split.map(&:to_i)
  
  rem = max(0, n - a.sum{ |ai| log2(ai) })

  ans = (1..n).map{ |i| log2(i) }.sort.reverse.sum do |i|
    if rem != 0 && rem - i >= 0
      rem -= i
      1
    else
      0
    end
  end

  puts rem == 0 ? ans : -1
end