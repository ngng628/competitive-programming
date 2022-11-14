# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, q = ints
imos = DynamicRangeSum.new(2*(n + 1), 0)
q.times do
  t, k = ints
  case t
  when 1
    parity = imos.get(0...k)
    puts parity.even? ? k : 2*n - k + 1
  when 2
    imos.add(n - k, 1)
    imos.add(n + k, -1)
  end
end


class DynamicRangeSum(T)
  getter size : Int32
  @data : Array(T)

  def initialize(n : Int)
    @data = Array(T).new(n){ T.zero }
    @size = @data.size
  end

  def initialize(n : Int, val : T)
    @data = Array(T).new(n){ val }
    @size = @data.size
  end

  def initialize(elems : Enumerable(T))
    @size = elems.size.to_i64
    @data = Array(T).new(@size, T.zero)
    elems.each_with_index{ |x, i| add(i, x) }
  end

  def get(left : Int, right : Int) : T
    raise IndexError.new("`left` and `right` must be 0 <= left <= right <= self.size (#{left}, #{right})") unless 0 <= left && left <= right && right <= @size
    sum(right) - sum(left)
  end

  def get?(left : Int, right : Int) : T?
    return nil unless 0 <= left && left <= right && right <= @size
    get(left, right)
  end

  def get(i : Int) : T
    get(i, i + 1)
  end

  def get?(i : Int) : T?
    get?(i, i + 1)
  end

  {% begin %}
    {% for int1 in Int.union_types + [Nil] %}
      {% for int2 in Int.union_types + [Nil] %}
        def get(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get(left, right)
        end

        def get?(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get?(left, right)
        end

        def [](range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get(left, right)
        end

        def []?(range : Range({{ int1.id }}, {{ int2.id }})) : T
          left = (range.begin || 0)
          right = range.end ? range.end.not_nil! + (range.exclusive? ? 0 : 1) : @size
          get?(left, right)
        end
      {% end %}
    {% end %}
  {% end %}

  def [](i : Int) : T; get(i, i + 1) end
  def []?(i : Int) : T?; get?(i, i + 1) end

  def [](l : Int, r : Int) : T; get(l, r) end
  def []?(l : Int, r : Int) : T?; get?(l, r) end

  def []=(i : Int, x : T) : T; add(i, x - get(i)) end

  def add(i : Int, x : T)
    i += 1
    while (i <= @size)
      @data[i - 1] += x
      i += i & -i
    end
    x
  end

  private def sum(r : Int) : T
    s = T.zero
    while r > 0
      s += @data[r - 1]
      r -= r & -r
    end
    s
  end
end