# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m = ints
sums = Array.new(n + 1){ 0_i64 }
adds = Array.new(n + 1){ Array({Int64, Int64}).new }
(1..m).each do
  l, r, a = ints
  sums[r] += a
  adds[r] << {l - 1, a}
end

dp = LazySegmentTree(Int64, Int64).range_add_range_max [0_i64] * (n + 1)
(1..n).each do |i|
  dp[i] = dp.prod(0...i) + sums[i]
  adds[i].each do |(l, a)|
    dp.apply(l + 1...i, a)
  end
end

puts dp.all_prod


class LazySegmentTree(S, F)
  include Enumerable(S)

  getter size : Int32

  @op : S, S -> S
  @mapping : F, S -> S
  @composition : F, F -> F

  @log : Int32
  @n : Int32
  @nodes : Array(S)
  @lazy_nodes : Array(F)

  def initialize(elems : Enumerable(S), @op : S, S -> S, @e : -> S, @mapping : F, S -> S, @composition : F, F -> F, @id : -> F)
    @size = elems.size

    @log = 0
    while ((1 << @log) < @size)
      @log += 1
    end
    @n = (1 << @log)

    @nodes = Array.new(2 * @n){ @e.call }
    @lazy_nodes = Array.new(@n){ @id.call }
    
    elems.each_with_index{ |x, i| @nodes[@n + i] = x }
    (1...@n).reverse_each do |i|
      update(i)
    end
  end

  def self.range_add_range_min(elems : Enumerable(S))
    op = ->(a : S, b : S){ a < b ? a : b }
    e = ->(){ S::MAX // 2 }
    mapping = ->(f : F, x : S){ f + x }
    composition = ->(f : F, g : F){ f + g }
    id = ->(){ F.zero }
    new elems, op, e, mapping, composition, id
  end

  def self.range_add_range_max(elems : Enumerable(S))
    op = ->(a : S, b : S){ a > b ? a : b }
    e = ->(){ S::MIN // 2 }
    mapping = ->(f : F, x : S){ f + x }
    composition = ->(f : F, g : F){ f + g }
    id = ->(){ F.zero }
    new elems, op, e, mapping, composition, id
  end

  def set(i : Int, val : S) : Nil
    raise IndexError.new unless 0 <= i && i < @size
    i += @n
    (1..@log).reverse_each{ |j| push(i >> j) }
    @nodes[i] = val
    (1..@log).each{ |j| update(i >> j)}
  end

  def at(i : Int) : S
    raise IndexError.new unless 0 <= i && i < @size
    i += @n
    (1..@log).reverse_each{ |j| push(i >> j) }
    @nodes[i]
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

  def prod(l : Int, r : Int) : S
    raise IndexError.new unless 0 <= l && l <= r && r <= @size
    return @e.call if l == r

    l += @n
    r += @n

    (1..@log).each do |i|
      j = @log - i + 1
      push(l >> j) if ((l >> j) << j) != l
      push((r - 1) >> j) if ((r >> j) << j) != r
    end

    sml, smr = @e.call, @e.call
    while l < r
      sml = @op.call(sml, @nodes[(l += 1) - 1]) if l.odd?
      smr = @op.call(@nodes[r -= 1], smr) if r.odd?
      l >>= 1
      r >>= 1
    end

    @op.call(sml, smr)
  end

  def prod?(l : Int, r : Int) : S?
    return nil unless 0 <= l && l <= r && r <= @size
    prod(l, r)
  end

  def prod(range : Range(Int, Int)) : S
    prod(range.begin, range.exclusive? ? range.end : range.end + 1)
  end

  def prod?(range : Range(Int, Int)) : S?
    prod?(range.begin, range.exclusive? ? range.end : range.end + 1)
  end

  def all_prod : S
    @nodes[1]
  end

  def all_prod? : S?
    @nodes[1]?
  end

  def apply(i : Int, f : F) : Nil
    raise IndexError.new unless 0 <= i && i < @size
    i += @n
    (1..@log).reverse_each{ |j| push(i >> j) }
    @nodes[i] = @mapping.call(f, @nodes[i])
    (1..@log).each{ |j| update(i >> j) }
  end

  def apply(l : Int, r : Int, f : F) : Nil
    raise IndexError.new unless 0 <= l && l <= r && r <= @size
    return if l == r

    l += @n
    r += @n

    (1..@log).reverse_each do |i|
      push(l >> i) if ((l >> i) << i) != l
      push((r - 1) >> i) if ((r >> i) << i) != r
    end

    l2, r2 = l, r
    while l < r
      all_apply((l += 1) - 1, f) if l.odd?
      all_apply(r -= 1, f) if r.odd?
      l >>= 1
      r >>= 1
    end
    l, r = l2, r2

    (1..@log).each do |i|
      update(l >> i) if ((l >> i) << i) != l
      update((r - 1) >> i) if ((r >> i) << i) != r
    end
  end

  def apply(range : Range(Int, Int), f : F)
    apply(range.begin, range.exclusive? ? range.end : range.end + 1, f)
  end

  def apply?(i : Int, f : F) : Bool
    return false unless 0 <= i && i < @size
    apply(i, f)
    true
  end

  def apply?(l : Int, r : Int, f : F) : Bool
    return false unless 0 <= l && l <= r && r <= @size
    apply(l, r, f)
    true
  end

  def apply?(range : Range(Int, Int), f : F) : Bool
    l = range.begin
    r = range.exclusive? ? range.end : range.end + 1
    return false unless 0 <= l && l <= r && r <= @size
    apply(l, r, f)
    true
  end

  def max_right(l : Int, ok : S -> Bool) : Int32
    raise IndexError.new unless 0 <= l && l <= @size
    raise "単位元 e で ok(e) == true である必要があります。" unless ok.call(@e.call)
    return @size if l == @size
    l += @n
    (1..@log).each{ |i| push(l >> i) }
    sm = @e.call
    loop do
      while l.even?
        l >>= 1
      end
      unless ok.call(@op.call(sm, @nodes[l]))
        while l < @n
          push(l)
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
    (1..@log).reverse_each{ |i| push((r - 1) >> i) }
    sm = @e.call
    loop do
      r -= 1
      while r > 1 && r.odd?
        r >>= 1
      end
      unless ok.call(@op.call(@nodes[r], sm))
        while r < @n
          push(r)
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

  def [](i : Int); at(i) end
  def []?(i : Int); at?(i) end
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

  private def update(k : Int) : Nil
    @nodes[k] = @op.call(@nodes[2 * k], @nodes[2 * k + 1])
  end

  private def all_apply(k : Int, f : F) : Nil
    @nodes[k] = @mapping.call(f, @nodes[k])
    @lazy_nodes[k] = @composition.call(f, @lazy_nodes[k]) if k < @n
  end

  private def push(k : Int) : Nil
    all_apply(2 * k, @lazy_nodes[k])
    all_apply(2 * k + 1, @lazy_nodes[k])
    @lazy_nodes[k] = @id.call
  end
end