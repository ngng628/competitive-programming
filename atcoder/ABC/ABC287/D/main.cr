# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

s = str.chars
n = s.size
t = str.chars
m = t.size

csum = DynamicRangeSum(Int32).new(m)
m.times do |i|
  csum[i] = (s[i - m] == '?' || t[i] == '?' || s[i - m] == t[i]) ? 1 : 0
end

left = 0
(m + 1).times do |ts|
  puts csum[0...m] == m ? "Yes" : "No"

  break if ts == m
  csum[left] = (s[left] == t[left] || s[left] == '?' || t[left] == '?') ? 1 : 0
  left += 1
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
    @size = elems.size.to_i32
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

  def set(i : Int, x : T)
    self[i] = x
  end

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
  def self.lcp(rh1 : self, rh2 : self, i : Int = 0, j : Int = 0) : Int32
    rh1.lcp(i, j, rh2)
  end

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

