# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints
csum = StaticRangeSum.new(a)

ans = OO
(0..n).each do |i|
  # P > Q となってしまう最小の添字
  ok = (0..i).bsearch { |j|
    csum[0...j] > csum[j...i]
  }
  next if ok.nil?

  c1 = {ok - 1, ok, ok + 1}

  ok = (i..n).bsearch { |j|
    csum[i...j] > csum[j...n]
  }
  next if ok.nil?

  c2 = {ok - 1, ok, ok + 1}

  c1.each do |x|
    c2.each do |z|
      y = i

      next unless x < y && y < z
      next unless x >= 1
      next unless z < n

      s = csum[0...x]
      t = csum[x...y]
      u = csum[y...z]
      v = csum[z...n]

      mn = {s, t, u, v}.min
      mx = {s, t, u, v}.max
      chmin(ans, (mx - mn).abs)
    end
  end
end

puts ans









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
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end
    get(left, right)
  end
  
  def get?(left, right) : T?
    return nil unless left <= right
    get(left, right)
  end

  def get?(range : Range(Int?, Int?)) : T?
    left = (range.begin || 0)
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end
    get?(left, right)
  end

  def get!(left, right) : T
    @csum[right] - @csum[left]
  end

  def get!(range : Range(Int?, Int?)) : T
    left = (range.begin || 0)
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end
    get!(left, right)
  end

  def [](left, right) : T; get(left, right) end
  def [](range : Range(Int?, Int?)) : T; get(range) end
  def []?(left, right) : T?; get?(left, right) end
  def []?(range : Range(Int?, Int?)) : T?; get?(range) end
end