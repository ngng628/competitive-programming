require "nglib/utils"

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

struct Int
  def divisors
    lo = Array(Int64).new
    hi = Array(Int64).new
    i = 1_i64
    while i**2 <= self
      if self % i == 0
        j = self // i
        lo << i
        if i != j
          hi << j
        end
      end
      i += 1
    end
    lo + hi
  end
end

struct Fraction
  include Comparable(Fraction)

  getter num : Int64
  getter den : Int64

  def self.zero
    new
  end

  def self.infinity
    new 1, 0
  end

  def initialize
    @num = 0_i64
    @den = 1_i64
  end

  def initialize(n : Int)
    @num = n.to_i64
    @den = 1_i64
  end

  def initialize(n : Int, d : Int)
    @num = n.to_i64
    @den = d.to_i64
    reduce
  end

  def initialize(s : String)
    pos = s.index(".")
    if pos.nil?
      @num = s.to_i64
      @den = 1
    else
      @den = 1_i64
      ten = 10_i64

      m = s.size - 1 - pos
      until m == 0
        @den *= ten if m.bit(0) == 1
        ten *= ten
        m >>= 1
      end

      @num = 0
      s.chars.each do |c|
        @num = 10_i64 * @num + c.to_i if c != '.'
      end
    end
    reduce
  end

  def infinity?
    @den == 0
  end

  def inv : Fraction
    Fraction.new(@den, @num)
  end

  def abs : Fraction
    Fraction.new(@num.abs, @den.abs)
  end

  def num=(n : Int)
    @num = n.to_i64
    reduce
  end

  def den=(d : Int)
    @den = d.to_i64
    reduce
  end

  def +(other : Fraction)
    l = infinity? || other.infinity? ? 1_i64 : @den.lcm(other.den)
    n = @num * (l // @den) + other.num * (l // other.den)
    Fraction.new(n, l)
  end

  def -(other : Fraction)
    l = infinity? || other.infinity? ? 1_i64 : @den.lcm(other.den)
    n = @num * (l // @den) - other.num * (l // other.den)
    Fraction.new(n, l)
  end

  def *(other : Fraction)
    g1 = @den.gcd(other.num)
    g2 = @num.gcd(other.den)
    n = (@num // g2) * (other.num // g1)
    d = (@den // g1) * (other.den // g2)
    Fraction.new(n, d)
  end

  def /(other : Fraction)
    g1 = @den.gcd(other.num)
    g2 = @num.gcd(other.den)
    n = (@num // g2) * (other.den // g1)
    d = (@den // g1) * (other.num // g2)
    Fraction.new(n, d)
  end

  def //(other : Fraction)
    self / other
  end

  def +(other : Int)
    Fraction.new(@num + @den * other, @den)
  end

  def -(other : Int)
    Fraction.new(@num - @den * other, @den)
  end

  def *(other : Int)
    g = infinity? ? 1_i64 : @den.gcd(other)
    Fraction.new(@num * (other // g), @den // g)
  end

  def /(other : Int)
    g = infinity? ? 1_i64 : @num.gcd(other)
    Fraction.new(@num // g, @den * (other // g))
  end

  def //(other : Int)
    self / ther
  end

  def //(other : Fraction)
    self // other
  end

  def +
    self
  end

  def -
    Fraction.new(-@num, @den)
  end

  # Note: オーバーフローの可能性があります。
  def <=>(other : Fraction)
    @num * other.den <=> @den * other.num
  end

  def to_f
    @num / @den
  end

  def to_i
    @num // @den
  end

  def to_i32
    (@num // @den).to_i32
  end

  def to_i64
    (@num // @den).to_i32
  end

  def to_s(io : IO)
    io << @num << '/' << @den
  end

  def inspect(io : IO)
    to_s(io)
  end

  # 約分をします。
  #
  # 分数が負の場合は分子が負になるようにします。
  #
  # @num != 0 かつ @den != 0 かつ分母分子が互いに素でないとき `true` を返します。
  def reduce : Bool
    if @den < 0
      @num *= -1
      @den *= -1
    end

    if @num == 0
      @den = 1
      false
    elsif @den == 0
      @num = 1
      false
    else
      g = @num.gcd(@den)
      @num //= g
      @den //= g
      g != 1
    end
  end
end

struct Int
  def to_frac
    Fraction.new(self)
  end
end

t = int
t.times do
  n = int
  (1..10**7).each do |den|
    divs = den.divisors
  end
end
