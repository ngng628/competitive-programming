# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, m, k = ints
a = ints


if k == m
  ans = 0_i64
  m.times do |i|
    ans += a[i]
  end
  puts ans
  (1_i64...n - m + 1).each do |i|
    ans -= a[i - 1]
    ans += a[i + m - 1]
    puts ans
  end
else

  heap1 = AATreeMultiset(Int64).new
  m.times do |i|
    heap1 << a[i]
  end
  
  ans = 0_i64
  heap2 = AATreeMultiset(Int64).new
  k.times do |i|
    v = heap1[i]
    ans += v
    heap2 << v
  end
  
  k.times do |i|
    heap1.delete_at(0)
  end
  
  puts ans
  
  
  (1_i64...n - m + 1).each do |i|
    if heap2.includes?(a[i - 1])
      ans -= a[i - 1]
      heap2.delete(a[i - 1])
      v = heap1[0]
      heap2 << v
      heap1.delete_at(0)
      ans += v
    else
      heap1.delete(a[i - 1])
    end
    mx = heap2.last
    heap2 << a[i + m - 1]
    ans += a[i + m - 1]
    mx = heap2[(-1) % heap2.size]
    ans -= mx
    heap1 << mx
    heap2.delete_at((-1) % heap2.size)
    puts ans
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

class Heap(T)
  include Comparable(Heap(T))

  delegate size, to: hp
  delegate empty?, to: hp
  getter hp : Array(T)

  def <=>(other : Heap(T))
    @hp <=> other.hp
  end

  def self.min
    new { |a, b| a > b }
  end

  def self.max
    new { |a, b| a < b }
  end

  def initialize
    @cmp = ->(a : T, b : T) { a < b }
    @hp = Array(T).new
  end

  def initialize(&@cmp : (T, T) -> Bool)
    @hp = Array(T).new
  end

  def <<(value : T)
    push(value)
  end

  def push(value : T)
    @hp.push(value)
    child = @hp.size - 1
    v = @hp[child]
    while child > 0
      parent = (child - 1) // 2
      unless @cmp.call @hp[parent], v
        break
      end
      @hp.swap(parent, child)
      child = parent
    end
    @hp[child] = v
  end

  def pop
    len = @hp.size - 1
    if len > 0
      v = @hp[len]
      @hp[len] = @hp[0]
      parent = 0
      child = 1
      while child < len
        if child + 1 < len && @cmp.call @hp[child], @hp[child + 1]
          child += 1
        end
        unless @cmp.call v, @hp[child]
          break
        end
        @hp.swap(parent, child)
        parent = child
        child = 2*parent + 1
      end
      @hp[parent] = v
    end
    @hp.pop
  end

  def peek
    @hp.first
  end

  def clear
    @hp.clear
  end
end