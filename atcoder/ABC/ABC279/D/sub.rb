a, b = gets.split.map(&:to_i)

f = ->(n){ a.to_f / Math.sqrt(1 + n) + b*n }

lo = 0
hi = 10**32 + 1
while hi - lo > 1
  mid = (lo + hi) / 2
  if f.call(mid) - f.call(mid - 1) < 0
    lo = mid
  else
    hi = mid
  end
end

puts sprintf("%.7f", f.call(lo))