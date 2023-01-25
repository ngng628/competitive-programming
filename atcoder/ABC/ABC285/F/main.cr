# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
s = str

base = RollingHash.create_base
rh = RollingHash.new(s, base)
s_hash = rh.hash(s)

hoge = rh.concat(2, 2, 2)

rh.lcp(0, 0)

mset = AATreeMultiset(Int64).new
n.times do |i|
  mset << rh.hash(s[i])
end


q = int
q.times do |i|
  query = str.split
  case query[0]
  when "1"
    x = query[1].to_i64 - 1
    c = query[2]

    
  when "2"
    l = query[1].to_i64 - 1
    r = query[2].to_i64
  end
end

set = AATreeSet(Int64).new
set.lower_bound_index(10)

class AATreeSet(T)
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
 
    node = find_node(@root, val)
    return false if node.not_nil!.key == val # NOT multi

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
    dfs = uninitialized Node(T) -> Nil
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


# ローリングハッシュを生成します。
class RollingHash
  MOD = (1_u64 << 61) - 1 

  getter size : Int32
  @base : UInt64
  @power : Array(UInt64)
  @hash : Array(UInt64)

  # 配列 a に対する、基数が base のロリハを構築します。
  #
  # base は指定しない場合、ランダムに生成されます。
  #
  # ```
  # rh = RollingHash.new([1, 2, 5, 1, 2])
  # ```
  def initialize(a : Array(Int), base : UInt64? = nil)
    initialize(a.size, a, base)
  end

  # 文字列 s に対する、基数が base のロリハを構築します。
  #
  # base は指定しない場合、ランダムに生成されます。
  #
  # ```
  # rh = RollingHash.new("missisippi")
  # ```
  def initialize(s : String, base : UInt64? = nil )
    initialize(s.size, s.bytes, base)
  end

  # Enumerable な列 a に対する、基数が base のロリハを構築します。
  #
  # base は指定しない場合、ランダムに生成されます。
  #
  # ```
  # rh = RollingHash.new([1, 2, 5, 1, 2])
  # ```
  def initialize(@size, a : Enumerable, base : UInt64? = nil)
    base = RollingHash.create_base if base.nil?
    @base = base.not_nil!

    @power = [1_u64] * (@size + 1)
    @hash = [0_u64] * (@size + 1)

    a.each_with_index do |x, i|
      @power[i + 1] = mul(@power[i], @base)
      @hash[i + 1] = mul(@hash[i], @base) + x.to_u64
      @hash[i + 1] -= MOD if @hash[i + 1] >= MOD
    end
  end

  # ランダムに基底を生成します。
  #
  # ```
  # base = RollingHash.create_base
  # base # => 1729
  # ```
  def self.create_base
    rand(628_u64..MOD - 2)
  end

  # 文字列 s のハッシュを返します。
  #
  # ```
  # rh = RollingHash.new("missisippi")
  # rh.hash("is") # => 339225237399054811
  # rh.hash("abc") # => 496222201481864933
  # ```
  def hash(s : String)
    hash(s.bytes)
  end

  # 列 s のハッシュを返します。
  #
  # ```
  # rh = RollingHash.new("missisippi")
  # rh.hash("is") # => 339225237399054811
  # rh.hash("abc") # => 496222201481864933
  # ```
  def hash(s : Enumerable)
    s.reduce(0_u64){ |acc, ti| mul(acc, @base) + ti.to_u64 }
  end

  # s[start...start + length] のハッシュを返します。
  #
  # ```
  # rh = RollingHash.new("missisippi")
  # rh.substr(4, length: 2) # => 339225237399054811
  # rh.substr(5, length: 2) # => 339225237399054811
  # ```
  def substr(start : Int, length : Int) : UInt64
    res = @hash[start + length] + MOD - mul(@hash[start], @power[length])
    res < MOD ? res : res - MOD
  end

  # rangeで指定した範囲 s[l...r] のハッシュを返します。
  #
  # ```
  # rh = RollingHash.new("missisippi")
  # rh.slice(4..5) # => 339225237399054811
  # rh.slice(5..6) # => 339225237399054811
  # ```
  def slice(range : Range(Int?, Int?)) : UInt64
    left = (range.begin || 0)
    right = if range.end.nil?
        @size
      else
        range.end.not_nil! + (range.exclusive? ? 0 : 1)
      end
  
    length = right - left

    substr(start: left, length: length)
  end

  # rangeで指定した範囲 s[l...r] のハッシュを返します。
  #
  # ```
  # rh = RollingHash.new("missisippi")
  # rh[4..5] # => 339225237399054811
  # rh[5..6] # => 339225237399054811
  # ```
  def [](range : Range(Int?, Int?)) : UInt64
    slice(range)
  end

  # ハッシュ値 h1 とハッシュ値 h2 を結合したときのハッシュ値を返します。
  #
  # ハッシュ値 h2 の元々の長さを渡す必要があります。
  #
  # ```
  # rh = RollingHash.new("missisippi")
  # h1 = rh[1..2] # "is"
  # h2 = rh[5..6] # "si"
  # h = rh.concat(h1, h2, h2_len: 2)
  # h == rh.[1..4] # => true
  # ```
  def concat(h1 : UInt64, h2 : UInt64, h2_len : Int) : UInt64
    res = mul(h1, @power[h2_len]) + h2
    res < MOD ? res : res - MOD
  end

  # s[i...] と other[j...] の最長共通接頭辞の長さを返します。
  #
  # other はデフォルトで自分自身を渡しています。
  # 自分自身以外を渡す場合は (mod, base) が一致している必要があります。
  #
  # ```
  # rh1 = RollingHash.new("missisippi")
  # rh1 = rh1.lcp(3, 5) # => 2
  # rh1 = rh1.lcp(0, 1) # => 0
  # ```
  def lcp(i : Int, j : Int, other = self) : Int32
    length = Math.min(@hash.size - i, @hash.size - j)

    ok = length - (1..length).bsearch{ |len|
      l = length - len
      self.substr(start: i, length: l) == other.substr(start: j, length: l)
    }.not_nil!

    return ok.to_i32
  end

  # s[i...] と t[j...] の最長共通接頭辞の長さを返します。
  #
  # i, j はデフォルトで 0 を渡しています。
  #
  # ```
  # rh1 = RollingHash.new("missisippi", base: 628)
  # rh2 = RollingHash.new("thisisapen", base: 628)
  # RollingHash.lcp(rh1, rh2) # => 0
  # RollingHash.lcp(rh1, rh2, 4, 2) # => 3
  # ```
  # def self.lcp(rh1 : self, rh2 : self, i : Int = 0, j : Int = 0) : Int32
  #   rh1.lcp(i, j, rh2)
  # end

  # 文字列検索を行います。
  #
  # s[offset..] から t と一致する初めての添字を返します。
  # 添字は s が基準です。また、offset が加算された値が返ります。
  #
  # 存在しない場合は nil を返します。
  #
  # ```
  # rh = RollingHash.new("missisippi", base: 628)
  # rh.index("is") # => 1
  # rh.index("is", offset: 4) # => 4
  # rh.index("mid") # => nil
  # rh.index("i") # => 1
  # rh.index("pi") # => 8
  # ```
  def index(t : String, offset : Int = 0) : Int32?
    index(t.bytes, offset)
  end

  # 検索を行います。
  #
  # s[offset..] から t と一致する初めての添字を返します。
  # 添字は s が基準です。また、offset が加算された値が返ります。
  #
  # 存在しない場合は nil を返します。
  #
  # ```
  # rh = RollingHash.new("missisippi", base: 628)
  # rh.index("is") # => 1
  # rh.index("is", offset: 4) # => 4
  # rh.index("mid") # => nil
  # rh.index("i") # => 1
  # rh.index("pi") # => 8
  # ```
  def index(t : Enumerable, offset : Int = 0) : Int32?
    ths = hash(t)
    t_len = t.size
    res = (offset..@size - t.size).index{ |i| ths == substr(i, t_len) }
    res ? res.not_nil! + offset : nil
  end

  # 文字列検索を行います。
  #
  # s[offset..] から t と一致する初めての添字を返します。
  # 添字は s が基準です。また、offset が加算された値が返ります。
  #
  # 存在しない場合は例外を投げます。
  #
  # ```
  # rh = RollingHash.new("missisippi", base: 628)
  # rh.index!("is") # => 1
  # rh.index!("is", offset: 4) # => 4
  # rh.index!("mid") # => Enumerable::NotFoundError
  # rh.index!("i") # => 1
  # rh.index!("pi") # => 8
  # ```
  def index!(t : String, offset : Int = 0) : Int32
    index!(t.bytes, offset)
  end

  # 検索を行います。
  #
  # s[offset..] から t と一致する初めての添字を返します。
  # 添字は s が基準です。また、offset が加算された値が返ります。
  #21
  # 存在しない場合は例外を投げます。
  #
  # ```
  # rh = RollingHash.new("missisippi", base: 628)
  # rh.index!("is") # => 1
  # rh.index!("is", offset: 4) # => 4
  # rh.index!("mid") # => Enumerable::NotFoundError
  # rh.index!("i") # => 1
  # rh.index!("pi") # => 8
  # ```
  def index!(t : Enumerable, offset : Int = 0) : Int32
    ths = 0_u64
    t.each{ |ti| ths = mul(ths, @base) + ti.to_u64 }
    t_len = t.size
    (offset..@size - t.size).index!{ |i| ths == substr(i, t_len) } + offset
  end

  @[AlwaysInline]
  private def mul(a : UInt64, b : UInt64) : UInt64
    t = a.to_u128 * b
    t = (t >> 61) + (t & MOD)
    (t < MOD ? t : t - MOD).to_u64
  end
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
    dfs = uninitialized Node(T) -> Nil
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