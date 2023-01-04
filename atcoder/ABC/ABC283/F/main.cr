# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
p = ints -1

a, sega = [OO] * n, SegmentTree.min([OO] * (n + 1))
b, segb = [OO] * n, SegmentTree.min([OO] * (n + 1))
(n - 1).downto(0) do |i|
  a[i] = sega[p[i] + 1..]
  sega[p[i]] = p[i] + i

  b[i] = segb[...p[i]]
  segb[p[i]] = i - p[i]
end

c, segc = [OO] * n, SegmentTree.min([OO] * (n + 1))
d, segd = [-OO] * n, SegmentTree.max([-OO] * (n + 1))
n.times do |i|
  c[i] = segc[p[i] + 1..]
  segc[p[i]] = p[i] - i

  d[i] = segd[...p[i]]
  segd[p[i]] = p[i] + i
end

ans = n.times.map do |i|
  [
    a[i] - (p[i] + i),
    b[i] - (i - p[i]),
    c[i] - (p[i] - i),
    p[i] + i - d[i],
  ].min
end

puts ans.join(" ")











class SegmentTree(S)
  include Enumerable(S)

  getter size : Int32
  delegate empty?, to: @nodes

  @op : S, S -> S
  @e : -> S

  @log : Int32
  @n : Int32
  @nodes : Array(S)

  def self.max(elems : Enumerable(S))
    new elems, ->(x : S, y : S){ x > y ? x : y }, ->(){ S::MIN // 2 }
  end

  def self.min(elems : Enumerable(S))
    new elems, ->(x : S, y : S){ x < y ? x : y }, ->(){ S::MAX // 2 }
  end

  def initialize(elems : Enumerable(S), @op : S, S -> S, @e : -> S)
    @size = elems.size

    @log = 0
    while ((1 << @log) < @size)
      @log += 1
    end
    @n = (1 << @log)

    @nodes = Array.new(2 * @n){ e.call }

    elems.each_with_index{ |x, i| @nodes[@n + i] = x}
    (1..@n - 1).reverse_each{ |i| update(i) }
  end

  def set(i : Int, val : S) : Nil
    raise IndexError.new unless 0 <= i && i < @size
    i += @n
    @nodes[i] = val
    (1..@log).each{ |j| update(i >> j) }
  end

  def at(i : Int) : S
    raise IndexError.new unless 0 <= i && i < @size
    @nodes[i + @n]
  end

  def at?(i : Int) : S?
    return nil unless 0 <= i && i < @size
    at(i)
  end

  def each(& : S ->)
    @size.times do |i|
      yield at(i)
    end
  end

  def prod(l, r) : S
    raise IndexError.new unless 0 <= l && l <= r && r <= @size
    sml, smr = @e.call, @e.call
    l += @n
    r += @n
    while l < r
      sml = @op.call(sml, @nodes[(l += 1) - 1]) if l.odd?
      smr = @op.call(@nodes[r -= 1], smr) if r.odd?
      l >>= 1
      r >>= 1
    end
    @op.call(sml, smr)
  end

  def prod(range : Range(Int?, Int?)) : S
    left = (range.begin || 0)
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end
    prod(left, right)
  end

  def prod?(l : Int, r : Int) : S?
    return nil unless 0 <= l && l <= r && r <= @size
  end

  def prod?(range : Range(Int?, Int?)) : S?
    left = (range.begin || 0)
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end
    prod?(left, right)
  end

  def all_prod
    @nodes[1]
  end

  def all_prod?
    @nodes[1]?
  end

  def max_right(l : Int, ok : S -> Bool) : Int32
    raise IndexError.new unless 0 <= l && l <= @size
    raise "単位元 e で ok(e) == true である必要があります。" unless ok.call(@e.call)
    return @size if l == @size
    l += @n
    sm = @e.call
    loop do
      while l.even?
        l >>= 1
      end
      unless ok.call(@op.call(sm, @nodes[l]))
        while l < @n
          l = 2 * l
          if ok.call(@op.call(sm, @nodes[l]))
            sm = @op.call(sm, @nodes[l])
            l += 1
          end
        end
        return (l - @n).to_i
      end
      sm = @op.call(sm, @nodes[l])
      l += 1
      break if (l & -l) == l
    end
    @size
  end

  def max_right?(l : Int, ok : S -> Bool) : Int32?
    return nil unless 0 <= l && l <= @size
    return nil unless ok.call(@e.call)
    max_right(l, ok)
  end

  def min_left(r : Int, ok : S -> Bool) : Int32
    raise IndexError.new unless 0 <= r && r <= @size
    raise "単位元 e で ok(e) == true である必要があります。" unless ok.call(@e.call)
    return 0 if r == 0
    r += @n
    sm = @e.call
    loop do
      r -= 1
      while r > 1 && r.odd?
        r >>= 1
      end
      unless ok.call(@op.call(@nodes[r], sm))
        while r < @n
          r = 2 * r + 1
          if ok.call(@op.call(@nodes[r], sm))
            sm = @op.call(@nodes[r], sm)
            r -= 1
          end
        end
        return (r + 1 - @n).to_i
      end
      break if (r & -r) == r
    end
    0
  end

  def min_left?(r : Int, ok : S -> Bool) : Int32?
    return nil unless 0 <= r && r <= @size
    return nil unless ok.call(@e.call)
    min_left(r, ok)
  end

  def [](i); at(i) end
  def [](range : Range(Int?, Int?)); prod(range) end
  def []?(i); at?(i) end
  def []?(range : Range(Int?, Int?)); prod?(range) end
  def []=(i : Int, val : S); set(i, val) end

  def to_a : Array(S)
    Array(S).new(@size){ |i| at(i) }
  end

  def to_s(io : IO)
    @size.times do |i|
      io << " " unless i == 0
      io << at(i)
    end
  end

  def inspect(io : IO); to_s(io) end

  private def update(k : Int)
    @nodes[k] = @op.call(@nodes[2 * k], @nodes[2 * k + 1])
  end
end