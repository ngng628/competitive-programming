# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

h, w = ints
x = (1..h).map{ ints }
csum = RectangleSum.new(x)

q = int
q.times do
  a, b, c, d = ints -1
  puts csum[a..c, b..d]
end

class RectangleSum(T)
  getter height : Int64
  getter width : Int64
  @csum : Array(Array(T))

  # @height, @width も範囲に含みます（閉区間）
  def initialize(matrix : Array(Array(T)))
    @height = matrix.size.to_i64
    @width = @height == 0 ? 0_i64 : matrix[0].size.to_i64
    @csum = Array.new(@height + 1){ Array.new(@width + 1){ T.zero } }
    @height.times do |i|
      @width.times do |j|
        @csum[i + 1][j + 1] = @csum[i][j + 1] + @csum[i + 1][j] - @csum[i][j] + matrix[i][j]
      end
    end
  end

  def get(y1, y2, x1, x2) : T
    @csum[y2][x2] - @csum[y1][x2] - @csum[y2][x1] + @csum[y1][x1]
  end

  # y in y_range, x in x_range の位置の値を返します。
  def get(y_range : Range(Int?, Int?), x1, x2) : T
    y1 = (y_range.begin || 0)
    y2 = (y_range.end || @height + 1) + (y_range.exclusive? ? 0 : 1)
    get(y1, y2, x1, x2)
  end

  # y in y_range, x in x_range の位置の値を返します。
  def get(y1, y2, x_range : Range(Int?, Int?)) : T
    x1 = (x_range.begin || 0)
    x2 = (x_range.end || @width + 1) + (x_range.exclusive? ? 0 : 1)
    get(y1, y2, x1, x2)
  end

  # y in y_range, x in x_range の位置の値を返します。
  def get(y_range : Range(Int?, Int?), x_range : Range(Int?, Int?)) : T
    y1 = (y_range.begin || 0)
    y2 = (y_range.end || @height + 1) + (y_range.exclusive? ? 0 : 1)
    x1 = (x_range.begin || 0)
    x2 = (x_range.end || @width + 1) + (x_range.exclusive? ? 0 : 1)
    get(y1, y2, x1, x2)
  end

  # {y, x} の位置の値を返します。
  def get(y, x) : Int64
    get(y, y + 1, x, x + 1)
  end

  def to_s(io : IO) : Nil
    io << @csum.to_s
  end

  def inspect(io : IO) : Nil
    to_s(io)
  end

  def [](y1, y2, x1, x2) : T
    get(y1, y2, x1, x2)
  end

  def get(y_range : Range(Int?, Int?), x1, x2) : T
    get(y_range, x1, x2)
  end

  def [](y1, y2, x_range : Range(Int?, Int?)) : T
    get(y1, y2, x_range)
  end

  def [](y_range : Range(Int?, Int?), x_range : Range(Int?, Int?)) : T
    get(y_range, x_range)
  end
end