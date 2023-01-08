rh1 = RollingHash.new("missisippi", base: 628)
rh2 = RollingHash.new("thisisapen", base: 628)

puts "missisippi"[4...]
puts "thisisapen"[2...]

puts rh1.lcp(3, 5) # => 2
puts rh1.lcp(0, 1) # => 0
puts rh1.lcp(4, 2, rh2) # => 0
puts RollingHash.lcp(rh1, rh2, 0, 0)
puts RollingHash.lcp(rh1, rh2, 4, 2)


class RollingHash
  getter size : Int32
  @@base : UInt64 = 0
  MOD = (1u64<< 61) - 1   # prime number
  def initialize(a : Array(Int), base : UInt64? = nil )
    initialize(a.size, a,  base)
  end
  def initialize(s : String, base : UInt64? = nil )
    initialize(s.size, s.bytes, base)
  end
  def initialize(@size, a : Enumerable, base : UInt64? = nil )
    if base.nil?
      @@base = rand(2u64..(MOD-2)) if @@base == 0
      base = @@base
    end
    @power = Array(UInt64).new(@size + 1, 1)
    @hash = Array(UInt64).new(@size + 1, 0)
    a.each_with_index do |x, i|
      @power[i + 1] = mul(@power[i], base)
      @hash[i + 1] = mul(@hash[i], base) + x.to_u64
      @hash[i + 1] -= MOD if @hash[i + 1] >= MOD
    end
  end
  @[AlwaysInline]
  def [](s : Int, len : Int)
    res = @hash[s + len] + MOD - mul(@hash[s], @power[len])
    res < MOD ? res : res - MOD
  end
  @[AlwaysInline]
  def [](range : Range)
    l = range.begin
    r = range.excludes_end? ? range.end : range.end+1
    len = r-l
    self.[](l,len)
  end
  def lcp(a, b, other = self)
    len = {@hash.size - a, @hash.size - b}.min
    low,high = 0,len
    pp! self[a, 0] != other[b, 0]
    # pp! self[a, len] != other[b, len]
    pp! self[a, len - 1] != other[b, len - 1]
    while high - low > 1
        mid = (low + high) >> 1
        if self[a, mid] != other[b, mid]
          high = mid
        else 
          low = mid
        end
    end
    puts self[s: a, len: low]
    puts other[s: b, len: low]
    return low
  end
  def self.lcp(rh1, rh2, a=0, b=0)
    rh1.lcp(a,b,rh2)
  end
  @[AlwaysInline]
  private def mul(a : UInt64, b : UInt64) : UInt64
    t = a.to_u128 * b
    t = (t >> 61) + (t & MOD)
    (t < MOD ? t : t - MOD).to_u64
  end
end
