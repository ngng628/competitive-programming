# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w, n = ints
imos = MatrixImos.new(h, w)
n.times do |i|
  y1, x1, y2, x2 = ints
  imos.add(y1..y2, x1..x2, 1_i64)
end

(1..h).each do |y|
  puts imos[y][1..w].join(" ")
end

class MatrixImos
  getter height : Int64
  getter width : Int64
  @shouldUpdate = true
  @memo : Array(Array(Int64))
  @csum : Array(Array(Int64))

  # @height, @width も範囲に含みます（閉区間）
  def initialize(@height, @width, val : Int64 = 0_i64)
    @memo = Array.new(@height + 2){ Array.new(@width + 2){ val } }
    @csum = Array.new(@height + 1){ Array.new(@width + 1){ 0_i64 } }
  end

  # y in [y1, y2], x in [x1, x2] の区間に val を足します。
  # 区間は閉区間です。
  def add(y1, y2, x1, x2, val = 1_i64) : Nil
    raise IndexError.new("`y1` must be less than or equal to `y2` (#{y1}, #{y2})") unless y1 <= y2
    raise IndexError.new("`x1` must be less than or equal to `x2` (#{x1}, #{x2})") unless x1 <= x2
    @shouldUpdate = true
    @memo[y1][x1] += val
    @memo[y1][x2] -= val
    @memo[y2][x1] -= val
    @memo[y2][x2] += val
  end

  # y in y_range, x in [x1, x2] の区間に val を足します。
  # 区間は閉区間です。
  def add(y_range : Range(Int?, Int?), x1, x2, val = 1_i64) : Nil
    y1 = (y_range.begin || 0)
    y2 = (y_range.end || @height + 1) + (y_range.exclusive? ? 0 : 1)
    add(y1, y2, x1, x2, val)
  end

  # y in [y1, y2], x in range の区間に val を足します。
  # 区間は閉区間です。
  def add(y1, y2, x_range : Range(Int?, Int?), val = 1_i64) : Nil
    x1 = (x_range.begin || 0)
    x2 = (x_range.end || @width + 1) + (x_range.exclusive? ? 0 : 1)
    add(y1, y2, x1, x2, val)
  end

  # y in y_range, x in range の区間に val を足します。
  # 区間は閉区間です。
  def add(y_range : Range(Int?, Int?), x_range : Range(Int?, Int?), val = 1_i64) : Nil
    y1 = (y_range.begin || 0)
    y2 = (y_range.end || @height + 1) + (y_range.exclusive? ? 0 : 1)
    x1 = (x_range.begin || 0)
    x2 = (x_range.end || @width + 1) + (x_range.exclusive? ? 0 : 1)
    add(y1, y2, x1, x2, val)
  end

  # index の位置の値を返します。
  def get(y : Int, x : Int) : Int64
    cumsum[y][x]
  end

  # index の位置の値を返します。
  def get?(y : Int, x : Int) : Int64
    return nil if csum[y].nil?
    cumsum[y][x]?
  end

  # いもす法の累積和を取った後の値を返します。
  def cumsum : Array(Array(Int64))
    update if @shouldUpdate
    @csum.dup
  end

  def each
    update if @shouldUpdate
    cumsum.each{ |v| yield v }
  end

  # いもす法の累積和を更新します。
  def update : Nil
    @csum = @memo.clone
    (@height + 1).times{ |y| (1..@width).each{ |x| @csum[y][x] += @csum[y][x - 1] } }
    (1..@height).each{ |y| (@width + 1).times{ |x| @csum[y][x] += @csum[y - 1][x] } }
    @shouldUpdate = false
  end

  def to_s(io : IO) : Nil
    io << cumsum.to_s
  end

  def inspect(io : IO) : Nil
    to_s(io)
  end

  def [](y : Int) : Array(Int64)
    cumsum[y]
  end

  def []?(y : Int) : Array(Int64)
    cumsum[x]
  end
end



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