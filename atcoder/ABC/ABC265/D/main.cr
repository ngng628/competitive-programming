# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, s, t, u = ints
a = ints

csum = StaticRangeSum.new(a)

sum = 0_i64
right = 0_i64
n.times do |left|
  while right < n && sum + a[right] <= t
    sum += a[right]
    right += 1
  end

  if sum == t
    ans = true
    # 左側を探す
    ok = left
    ng = -1_i64
    while (ok - ng).abs > 1
      mid = (ok + ng) // 2
      if csum[mid...left] <= s
        ok = mid
      else
        ng = mid
      end
    end
    ans &= csum[ok...left] == s

    ok = right
    ng = n + 1
    while (ok - ng).abs > 1
      mid = (ok + ng) // 2
      if csum[right...mid] <= u
        ok = mid
      else
        ng = mid
      end
    end
    ans &= csum[right...ok] == u

    if ans
      puts "Yes"
      exit
    end
  end

  if left == right
    right += 1
  else
    sum -= a[left]
  end
end

puts "No"


class StaticRangeSum(T)
  getter size : Int64
  getter csum : Array(T)

  def initialize(array : Array(T))
    @size = array.size.to_i64
    @csum = Array.new(@size + 1, T.zero)
    @size.times { |i| @csum[i + 1] = @csum[i] + array[i] }
  end

  def get(left, right) : T
    raise IndexError.new("`left` must be less than or equal to `right` (#{left}, #{right})") unless left <= right
    @csum[right] - @csum[left]
  end

  def get(range : Range(Int?, Int?)) : T
    left = (range.begin || 0)
    right = (range.end || @size) + (range.exclusive? ? 0 : 1)
    get(left, right)
  end
  
  def get?(left, right) : T?
    return nil unless left <= right
    get(left, right)
  end

  def get?(range : Range(Int?, Int?)) : T?
    left = (range.begin || 0)
    right = (range.end || @size) + (range.exclusive? ? 0 : 1)
    get?(left, right)
  end

  def get!(left, right) : T
    @csum[right] - @csum[left]
  end

  def get!(range : Range(Int?, Int?)) : T
    left = (range.begin || 0)
    right = (range.end || @size) + (range.exclusive? ? 0 : 1)
    get!(left, right)
  end

  def [](left, right) : T; get(left, right) end
  def [](range : Range(Int?, Int?)) : T; get(range) end
  def []?(left, right) : T?; get?(left, right) end
  def []?(range : Range(Int?, Int?)) : T?; get?(range) end
end