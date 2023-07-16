require "nglib/utils"

n, m = ints

shohin = Array.new(n) {
  line = ints
  p = line[0]
  c = line[1]
  f = line[2..]
  box = Array.new(m) { false }
  f.each do |fi|
    box[fi - 1] = true
  end
  {p, c, box}
}

ans = n.times.any? { |i|
  n.times.any? { |j|
    next false if i == j
    {
      shohin[i][0] >= shohin[j][0],
      m.times.all? { |k|
        if shohin[i][2][k]
          shohin[j][2][k]
        else
          true
        end
      },
      (shohin[i][0] > shohin[j][0] || m.times.any? { |k| shohin[j][2][k] && !shohin[i][2][k] })
    }.all?
  }
} ? "Yes" : "No"

puts ans
