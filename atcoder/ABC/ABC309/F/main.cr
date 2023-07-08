require "nglib/utils"

class SegmentTree(S)
  include Enumerable(S)

  getter size : Int32
  delegate empty?, to: @nodes

  @op : S, S -> S
  @e : -> S

  @height : Int32
  @n : Int32
  @nodes : Array(S)

  def self.max(elems : Enumerable(S))
    new elems, ->(x : S, y : S){ x > y ? x : y }, ->(){ S::MIN }
  end

  def self.min(elems : Enumerable(S))
    new elems, ->(x : S, y : S){ x < y ? x : y }, ->(){ S::MAX }
  end

  def initialize(elems : Enumerable(S), @op : S, S -> S, @e : -> S)
    @size = elems.size

    @height = log2_ceil(@size)
    @n = 1 << @height

    @nodes = Array.new(2 * @n){ e.call }

    elems.each_with_index{ |x, i| @nodes[@n + i] = x}
    (1..@n - 1).reverse_each{ |i| update(i) }
  end

  def set(i : Int, val : S) : Nil
    raise IndexError.new unless 0 <= i && i < @size
    i += @n
    @nodes[i] = val
    (1..@height).each{ |j| update(i >> j) }
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
    prod(l, r)
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

  def max_right(l : Int, & : S -> Bool) : Int32
    raise IndexError.new unless 0 <= l && l <= @size
    raise "単位元 e で ok(e) == true である必要があります。" unless yield @e.call
    return @size if l == @size
    l += @n
    sm = @e.call
    loop do
      while l.even?
        l >>= 1
      end
      unless (yield @op.call(sm, @nodes[l]))
        while l < @n
          l = 2 * l
          if (yield @op.call(sm, @nodes[l]))
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

  def max_right?(l : Int, & : S -> Bool) : Int32?
    return nil unless 0 <= l && l <= @size
    return nil unless yield @e.call
    max_right(l){ |x| yield x }
  end

  def min_left(r : Int, & : S -> Bool) : Int32
    raise IndexError.new unless 0 <= r && r <= @size
    raise "単位元 e で ok(e) == true である必要があります。" unless yield @e.call
    return 0 if r == 0
    r += @n
    sm = @e.call
    loop do
      r -= 1
      while r > 1 && r.odd?
        r >>= 1
      end
      unless yield @op.call(@nodes[r], sm)
        while r < @n
          r = 2 * r + 1
          if yield @op.call(@nodes[r], sm)
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

  def min_left?(r : Int, & : S -> Bool) : Int32?
    return nil unless 0 <= r && r <= @size
    return nil unless yield @e.call
    min_left(r){ |x| yield x }
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

  @[AlwaysInline]
  private def log2_ceil(n : Int32) : Int32
    log2_floor = 31 - n.leading_zeros_count
    log2_floor + ((n & n - 1) == 0 ? 0 : 1)
  end
end


#                                           .O,                                        
#                                          :o.                                         
#                                        'd'          :c;.                            c
#                                       lc  dKl     ;d,.,cl:.           oOx.           
#                                     .x.   .,.   'd:.......:ll;.       'lc            
#                                   .;0;        .ol............'col;.                  
#                                .:do;xl       cd'.................,col;.              
#                           .,cdd:'   od     'x;........:..............':ol;.          
#                     ..;lddc,.       od    od....l:...;x.........,........,lo;        
#              .,:loodl;.          .,,kx. .kk:....k,...lo........od.........;.:x,      
#       .,coool:,.                  ....;lkodl....O:...dk.......;Oo........:x...oo     
#    :dl;'.                                .lk:...Ok...xkc......xcx.......,k'....:x    
#  ;k,                                        :x:.Olx'.O'd;....;o.O......;Oc......cx   
#  O,                       .                   ;xO;.cOO..ll,..l: x,...,dck,.......dc  
#  k:                      lKd                    oO. KK   .;cld; dc;lOc.;d........,0  
#  dl                       .                      cx.cO.         .,.KW..x'.........0. 
#  oc         .ll;.                                 :k.l:            ;l,k,...;:.....0. 
#  o,         kkxkOOOOOOOOOkkkkxl:'.                 ;x.,.           .dOoccod:.....cO  
#  x..o.     lOxxxxxxxxxxxxxxxxxxkXOOdc'              oc    .l;,,,;coo:...ol......o0,  
#  O  '     xOxxxxxxxxxxxxxxxxxxxxKOxxkOOd;           .0.   '0:ccc:,,,0ccd;....;lx0l   
# .x      .Okxxxxxxxxxxxxxxxxxxxxx0KxxxxxxkOo.         O'    do'''''''OllOkoooolckl    
# ;l     .OkxxxxxxxxxxxxxxxxxxxxxxOKxxxxxkOxk0l        kkollll0kdoddxkK0Oxllooool.     
# c:     kKxxxxxxxxxxxxxxxxxxxxxxx0XkxxxxkXxxxOO       k'  ;d. .k,....':ok0dc;..   .'::
# o,    xO00xxxxxxxxxxxxxxxxxxxxxxKOKxxxxxXdoOk0;     .O  ;d  .k.         .cd,ckccc;lx,
# d,   c0xx0Kkxxxxxxxxxxxxxxxxxxx0O.KkxxxkX. .0K;     lk:lOo;;Oo;kd;     ' .x;:c      .
# d,  .0KxxxkK0kxxxxxxxxxxxxxxxx0k. l0xxxOx   O0     'O::k; .kckO: Okollxxkx. k.       
# d,  xod0xxxxK00OxxxxxxxxxxxxO0l.  'XxxkK'  ;K,    .Oxxo.  .o x: ;O;;xo..K. l:        
# l;  0:;d0xxxkO.;ok0OkO00OkO0l.     KkkKc';d0,   ;olxx     ,dd; 'Kkkk, 'Oc 'x         
# :l  K:;;o0kxxKc   .':c..:o,.       O0OlO0Kd. 'ol. :d      lO' ;00x;. ck'  O.         
# 'x  0c;;;cO0xkXk,               '. cdk00x..cOx   ol     .od.  ,c.  'k;   d;          
#  0. kl;;;;;oO0OK0,              ,ccO00KOokk.'x. o:   'cx0; .::c:. od    ;d           
#  ;d..xd:;;;;;cdkkk,...    ..';llc::,...   ;d..xkc  .klld.      ol ol   .k            
#    ,llokkolcccloddkK0K00ck00xodoo:.         cl '   .o..d:      c. ,k   k.            
#       .,:c::;,..  ;d  .0;k. ;lodxkKo         .d'        :x;'.....:xc  lc             
#                   lx :OOOol       'O           :o.        dOooodd0.  .O              
#                  lxc:,k:O .d;     ll            .dc        ld;;;;O'  l;              
#               .c, dk:k;.k   oOcc,,O.              ,x.       Oc;;;x:  x.              
#             .ld.'lkd;,:cdlc;;0, .:'                 dxcc:;,'kdllld0;',..    ;loodoool
#           ,ol.     .oo.    ...' .:::cccl:.           :x. .............';codOc;;;;;;;;
#        :kd,          co                 .'c,          'k.                  ,dx:;;;;;;
#         .:llld;,;:....O'                               .x:                  .ko;;;;;;
#               'lkcodxdxO.                                ;x,                :kc;;;;;;
#                ;k;;;;;;dx                                  o0'               ;Kd;;;;;

class Array(T)
  def compress
    b = clone.sort.uniq
    map{ |s| b.bsearch_index{ |x| x >= s } || b.size }
  end
end

n = int
boxies2 = Array.new(n) { h, w, d = ints; [h, w, d].sort }.sort
hs = boxies2.map(&.[0]).compress.map(&.to_i64)
ws = boxies2.map(&.[1]).compress.map(&.to_i64)
ds = boxies2.map(&.[2]).compress.map(&.to_i64)

boxies = (0...n).map { |i| {hs[i], ws[i], ds[i]} }.sort

seg = SegmentTree.min([OO] * n)
boxies.group_by(&.[0]).each_value do |b|
  b.each do |_, w, d|
    mn = seg[0...w]
    if mn < d
      puts "Yes"
      exit
    end
  end
  b.each do |_, w, d|
    chmin(seg[w], d)
  end
end

puts "No"
