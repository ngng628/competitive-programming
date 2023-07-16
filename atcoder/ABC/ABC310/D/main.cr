require "nglib/utils"
require "atcoder/dsu"

n, t, m = ints
ab = (1..m).map { a, b = ints.map(&.to_i32.pred); {a, b} }

ans = 0_i64
dfs = uninitialized Array(Array(Int64)), Int64 -> Nil
dfs = ->(ary : Array(Array(Int64)), i : Int64) do
  if i == n
    return if ary.any? { |a| a == [] of Int64 }
    ut = AtCoder::DSU.new(n)
    ary.each do |members|
      (members.size - 1).times { |j| ut.merge(members[j], members[j + 1]) }
    end
    res = ab.any? { |(a, b)|
      ut.same?(a, b)
    }
    ans += 1 if !res
    return nil
  end
  t.times do |ti|
    if ary[ti].empty?
      ary[ti] << i
      dfs.call(ary, i + 1)
      ary[ti].pop
      break 
    else
      ary[ti] << i
      dfs.call(ary, i + 1)
      ary[ti].pop
    end
  end
  nil
end

phi = Array.new(t) { [] of Int64 }
dfs.call(phi, 0_i64)
puts ans
