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

csum = DynamicRangeSum.new(2 * 10**5 + 2, 0.to_m)
multiset = AATreeMultiset(Int64).new
sum = 0
a.each_with_index do |ai, k|
  less = multiset.upper_bound_index(ai)
  sum += ai.to_m + (less.to_m * ai + csum[ai + 1..]) * 2
  ans = sum / ((k.to_m + 1)**2)
  puts ans
  multiset << ai
  csum.add(ai, ai.to_m)
end









class AATreeMultiset(T)
  include Enumerable(T)
 
  private class Node(T)
    property left : Node(T)?
    property right : Node(T)?
    property parent : Node(T)?
    property key : T
    property level : Int32
    property size : Int32
 
    def initialize(val : T)
      @left = @right = @parent = nil
      @level = 1
      @key = val
      @size = 1
    end
 
    def rotate_left : Node(T)
      right = @right.not_nil!
      mid = right.left
      par = @parent
      if right.parent = par
        if par.not_nil!.left == self
          par.not_nil!.left = right
        else
          par.not_nil!.right = right
        end
      end
      mid.parent = self if @right = mid
      right.left = self
      @parent = right
 
      sz = @size
      @size += (mid ? mid.size : 0) - right.size
      right.size = sz
 
      right
    end
 
    def rotate_right : Node(T)
      left = @left.not_nil!
      mid = left.right
      par = @parent
 
      if left.not_nil!.parent = par
        if par.not_nil!.left == self
          par.not_nil!.left = left
        else
          par.not_nil!.right = left
        end
      end
      mid.parent = self if @left = mid
      left.not_nil!.right = self
      @parent = left
 
      sz = @size
      @size += (mid ? mid.size : 0) - left.size
      left.size = sz
 
      left
    end
 
    def left_side?(node : Node(T)?) : Bool
      @left == node
    end
 
    def assign(node : Node(T)) : T
      @key = node.key
    end
  end
 
  @root : Node(T)?
 
  private def find_node(node : Node(T)?, val : T) : Node(T)?
    return nil unless node
    until val == node.not_nil!.key
      if val < node.not_nil!.key
        break unless node.not_nil!.left
        node = node.not_nil!.left
      else
        break unless node.not_nil!.right
        node = node.not_nil!.right
      end
    end

    while node.not_nil!.left && node.not_nil!.left.not_nil!.key == val
      node = node.not_nil!.left
    end
    while node.not_nil!.right && node.not_nil!.right.not_nil!.key == val
      node = node.not_nil!.right
    end

    node
  end
 
  private def find_node2(node : Node(T)?, val : T) : Node(T)?
    return nil unless node
    loop do
      if val <= node.not_nil!.key
        break unless node.not_nil!.left
        node = node.not_nil!.left
      else
        break unless node.not_nil!.right
        node = node.not_nil!.right
      end
    end
 
    node
  end
 
  private def skew(node : Node(T)?) : Node(T)?
    return nil unless node
    left = node.not_nil!.left
    if left && node.not_nil!.level == left.not_nil!.level
      return node.not_nil!.rotate_right
    end
    node
  end
 
  private def split(node : Node(T)?) : Node(T)?
    return nil unless node
    right = node.right
    if right && right.not_nil!.right && node.level == right.not_nil!.right.not_nil!.level
      r = node.rotate_left
      r.level += 1
      return r
    end
    node
  end
 
  private def begin_node : Node(T)?
    return nil unless @root
    node = @root
    while node.not_nil!.left
      node = node.not_nil!.left
    end
    node
  end
 
  private def next_node(node : Node(T)) : Node(T)?
    if node.right
      node = node.right
      while node.not_nil!.left
        node = node.not_nil!.left
      end
      node
    else
      while node
        par = node.not_nil!.parent
        if par && par.not_nil!.left_side?(node)
          return par
        end
        node = par
      end
      node
    end
  end
 
  private def level(node : Node(T)?)
    node ? node.level : 0
  end
 
  def initialize
    @root = nil
    self
  end
 
  def initialize(enumerable : Enumerable(T))
    @root = nil
    concat(enumerable)
    self
  end
 
  def concat(elems) : self
    elems.each { |elem| self << elem }
    self
  end
 
  def includes?(val : T) : Bool
    node = find_node(@root, val)
    node.nil? ? false : node.key == val
  end
 
  def clear
    @root = nil
  end
 
  def empty? : Bool
    @root.nil?
  end
 
  def at(k : Int) : T
    raise IndexError.new unless 0 <= k && k < size
    node = @root
    k += 1
    loop do
      left_size = (node.not_nil!.left ? node.not_nil!.left.not_nil!.size : 0) + 1
      break if left_size == k
 
      if k < left_size
        node = node.not_nil!.left
      else
        node = node.not_nil!.right
        k -= left_size
      end
    end
    node.not_nil!.key
  end
 
  def at?(k : Int) : T?
    return nil unless 0 <= k && k < size
    at(k)
  end
 
  def each(& : T ->)
    node = begin_node
    while node
      yield node.not_nil!.key
      node = next_node(node.not_nil!)
    end
  end

  def add(val : T) : Nil
    add?(val)
    nil
  end
 
  def add?(val : T) : Bool
    unless @root
      @root = Node.new(val)
      return true
    end
 
    node = find_node2(@root, val)
 
    new_node = Node.new(val)
    if val <= node.not_nil!.key
      node.not_nil!.left = new_node
    else
      node.not_nil!.right = new_node
    end
    new_node.not_nil!.parent = node
 
    node = new_node
    while node
      node = split(skew(node))
      unless node.not_nil!.parent
        @root = node
        break
      end
      node = node.not_nil!.parent
      node.not_nil!.size += 1
    end
    true
  end
 
  def delete(val : T) : Bool
    return false unless @root
 
    node = find_node(@root, val)
    return false unless node.not_nil!.key == val
 
    if node.not_nil!.left || node.not_nil!.right
      child = find_node(node.not_nil!.left ? node.not_nil!.left : node.not_nil!.right, val)
      node.not_nil!.assign(child.not_nil!)
      node = child
    end
 
    par = node.not_nil!.parent
    if par
      if par.not_nil!.left_side?(node)
        par.left = nil
      else
        par.right = nil
      end
    else
      @root = nil
    end
    node = par
 
    while node
      new_level = { level(node.left), level(node.right) }.min + 1
      if new_level < node.level
        node.level = new_level
        if new_level < level(node.right)
          node.right.not_nil!.level = new_level
        end
      end
 
      node.size -= 1
      node = skew(node).not_nil!
      skew(node.right.not_nil!.right) if skew(node.right)
 
      node = split(node)
      split(node.not_nil!.right)
 
      unless node.not_nil!.parent
        @root = node
        break
      end
      node = node.not_nil!.parent
    end
    true
  end
 
  def delete_at(k : Int) : Bool
    delete(at(k))
  end
 
  def delete_at?(k : Int) : Bool
    val = at?(k)
    if val
      delete(val)
    else
      return false
    end
  end
 
  def lower_bound_index(val : T) : Int32
    node = @root
    return 0 unless node
    index = 0
    while node
      if val <= node.not_nil!.key
        node = node.not_nil!.left
      else
        index += (node.not_nil!.left ? node.not_nil!.left.not_nil!.size : 0) + 1
        node = node.not_nil!.right
      end
    end
    index
  end
 
  def upper_bound_index(val : T) : Int32
    node = @root
    return 0 unless node
    index = 0
    while node
      if val < node.not_nil!.key
        node = node.not_nil!.left
      else
        index += (node.not_nil!.left ? node.not_nil!.left.not_nil!.size : 0) + 1
        node = node.not_nil!.right
      end
    end
    index
  end

  def less_index(val : T) : Int32?
    index = lower_bound_index(val)
    index == 0 ? nil : index - 1
  end
  
  def less_equal_index(val : T) : Int32?
    index = lower_bound_index(val)
    val == at?(index) ? index : (index == 0 ? nil : index - 1)
  end
  
  def greater_index(val : T) : Int32?
    index = upper_bound_index(val)
    index == size ? nil : index
  end
  
  def greater_equal_index(val : T) : Int32?
    index = lower_bound_index(val)
    index == size ? nil : index
  end

  def first : T; at(0) end
  def first? : T?; at?(0) end
  def last : T; at(size - 1) end
  def last? : T?; at?(size - 1) end
 
  def count(val : T) : Int32
    upper_bound_index(val) - lower_bound_index(val)
  end
 
  def size : Int32
    @root ? @root.not_nil!.size : 0
  end
 
  def to_a : Array(T)
    res = Array(T).new
    return res unless @root
    dfs = uninitialized Proc(Node(T), Nil)
    dfs = ->(node : Node(T)) do
      dfs.call(node.left.not_nil!) if node.left
      res << node.key
      dfs.call(node.right.not_nil!) if node.right
      nil
    end
    dfs.call(@root.not_nil!)
    res
  end
 
  def to_s(io : IO) : Nil
    io << "{" + to_a.join(", ") + "}"
  end

  def inspect(io : IO) : Nil
    to_s(io)
  end

  def ==(other : AATreeSet(T)) : Bool; self.to_a == other.to_a end
  def <<(val : T) : Bool; add?(val) end
  def [](k : Int) : T; at(k) end
  def []?(k : Int) : T | Nil; at?(k) end
end

def modinv(a : Int64, mod : Int64) : Int64
  b = mod
  u = 1_i64
  v = 0_i64
  until b == 0
    t = a // b
    a -= t * b
    a, b = b, a
    u -= t * v
    u, v = v, u
  end
  u % mod
end

def modpow(a : Int64, n : Int64, mod : Int64) : Int64
  res = 1_i64
  until n == 0
    res = res * a % mod if n.odd?
    a = a * a % mod
    n >>= 1
  end
  res
end

macro static_modint(modint, mod)
  struct {{ modint }}  
    include Comparable({{ modint }})

    MOD = {{ mod }}
    getter val : Int64

    delegate popcount, to: val
    delegate trailing_zeros_count, to: val

    def initialize
      @val = 0
    end

    def initialize(@val : Int64)
      @val %= {{ mod }}
    end

    def + : self; self end
    def - : self; {{ modint }}.new -@val end

    def +(other : self) : self; {{ modint }}.new @val + other.val end
    def -(other : self) : self; {{ modint }}.new @val - other.val end
    def *(other : self) : self; {{ modint }}.new @val * other.val end
    def /(other : self) : self; {{ modint }}.new @val * other.inv.val end
    def //(other : self) : self; self / other end

    def +(other : Int) : self; {{ modint }}.new @val + other end
    def -(other : Int) : self; {{ modint }}.new @val - other end
    def *(other : Int) : self; {{ modint }}.new @val * other end
    def **(other : Int) : self; self.pow(other.to_i64) end
    def /(other : Int) : self; {{ modint }}.new @val * modinv(other.to_i64, {{ mod }}) end
    def //(other : Int) : self; self / other end

    def <=>(other : self) : Int32; @val <=> other.val end
    
    def inv : self
      {{ modint }}.new modinv(@val, {{ mod }})
    end

    def pow(n : Int64) : self
      {{ modint }}.new modpow(@val, n, {{ mod }})
    end

    def abs : self
      self
    end

    def zero? : Bool
      @val == 0_i64
    end

    def self.zero : self
      {{ modint }}.new 0_i64
    end

    def clone
      {{ modint }}.new @val
    end

    def to_i; @val.to_i end
    def to_i32; @val.to_i32 end
    def to_i64; @val.to_i64 end
    def to_s(io : IO); io << @val end
    def inspect(io : IO); to_s(io) end
  end

  struct Int
    def to_m
      {{ modint }}.new self.to_i64
    end

    def +(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} + other.val end
    def -(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} - other.val end
    def *(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} * other.val end
    def /(other : {{ modint }}) : {{ modint }}; {{ modint }}.new self.to_i64 % {{ mod }} * other.inv.val end
    def //(other : {{ modint }}) : {{ modint }}; self.to_i64 / other end
  end
end
# static_modint(ModInt1000000007, 1_000_000_007_i64)
static_modint(ModInt998244353, 998_244_353_i64)
alias ModInt = ModInt998244353

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