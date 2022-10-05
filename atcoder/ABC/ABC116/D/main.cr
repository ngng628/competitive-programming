# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int64, b : Int64) : Int64; a < b ? a : b end
def max(a : Int64, b : Int64) : Int64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, k = ints
sushis = (0...n).map do
  t, d = ints
  [t - 1, d]
end

sushis.sort!{ |(t1, d1), (t2, d2)| d2 <=> d1 }
selects = sushis[...k]

sum = selects.sum{ |(t, d)| d }

tally = Array.new(n, 0_i64)
selects.each{ |(t, _)| tally[t] += 1 }
cnt = tally.count{ |x| x >= 1 }.to_i64

heap = Heap({Int64, Int64}).min
selects.each{ |(t, d)| heap << {d, t} if tally[t] >= 2 }

ans = sum + cnt**2
(sushis[k..]? || [] of Array(Int64)).each do |(t, d)|
  next unless tally[t] == 0

  ok = false
  until heap.empty?
    d2, t2 = heap.pop
    if tally[t2] >= 2
      tally[t2] -= 1
      sum -= d2
      ok = true
      break
    end
  end

  if ok
    tally[t] += 1
    cnt += 1
    sum += d
  end

  chmax(ans, sum + cnt**2)
end

puts ans

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