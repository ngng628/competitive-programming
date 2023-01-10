mat = [[1,3,4],
[9,2,7],
[5,8,6]]

# mat = [[1, 3],
# [4, 2]]

n = mat.size
require 'set'
set = Set.new
n.times do |i|
  n.times do |j|
    x = mat[i][j]
    set << (x - mat[i - 1][j]).abs if i - 1 >= 0
    set << (x - mat[i + 1][j]).abs if i + 1 < n
    set << (x - mat[i][j - 1]).abs if j - 1 >= 0
    set << (x - mat[i][j + 1]).abs if j + 1 < n
  end
end

puts set.size