require "nglib/utils"

# ac-library.cr by hakatashi https://github.com/google/ac-library.cr
#
# Copyright 2023 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require "atcoder/math"

module AtCoder
  # Implements [atcoder::static_modint](https://atcoder.github.io/ac-library/master/document_en/modint.html).
  #
  # ```
  # AtCoder.static_modint(ModInt101, 101_i64)
  # alias Mint = AtCoder::ModInt101
  # Mint.new(80_i64) + Mint.new(90_i64) # => 89
  # ```
  macro static_modint(name, modulo)
    module AtCoder
      # Implements atcoder::modint{{modulo}}.
      #
      # ```
      # alias Mint = AtCoder::{{name}}
      # Mint.new(30_i64) // Mint.new(7_i64)
      # ```
      {% if modulo == 998_244_353 || modulo == 1_000_000_007 || modulo == 998_244_353_i64 || modulo == 1_000_000_007_i64 %}
        struct {{name}}
          {% if modulo == 998_244_353 %}
            MOD = 998_244_353_i64
            M = 998_244_353_u32
            R = 3_296_722_945_u32
            MR = 998_244_351_u32
            M2 = 932_051_910_u32
          {% elsif modulo == 1_000_000_007 %}
            MOD = 1_000_000_007_i64
            M = 1_000_000_007_u32
            R = 2_068_349_879_u32
            MR = 2_226_617_417_u32
            M2 = 582_344_008_u32
          {% end %}

          getter mgy : UInt32

          # Initialize using montgomery representation
          def self.raw(mgy : UInt32)
            ret = new
            ret.mgy = mgy
            ret
          end

          def self.zero
            new 0
          end

          def initialize
            @mgy = 0
          end

          def initialize(value)
            @mgy = reduce(((value % M).to_u64 + M) * M2)
          end

          @@factorials = Array(self).new

          def self.factorial(n)
            if @@factorials.empty?
              # Change the initial capacity of this array to improve performance
              @@factorials = Array(self).new(100_000_i64)
              @@factorials << self.new(1)
            end
            @@factorials.size.upto(n) do |i|
              @@factorials << @@factorials.last * i
            end
            @@factorials[n]
          end

          def self.permutation(n, k)
            raise ArgumentError.new("k cannot be greater than n") unless n >= k
            factorial(n) // factorial(n - k)
          end

          def self.combination(n, k)
            raise ArgumentError.new("k cannot be greater than n") unless n >= k
            permutation(n, k) // @@factorials[k]
          end

          def self.repeated_combination(n, k)
            combination(n + k - 1, k)
          end

          def clone
            ret = self.class.new
            ret.mgy = @mgy
            ret
          end

          def +(value)
            self + self.class.new(value)
          end

          def +(value : self)
            ret = self.class.raw(@mgy)
            ret.mgy = (ret.mgy.to_i64 + value.mgy - 2*M).to_u32!
            if ret.mgy.to_i32! < 0
              ret.mgy = (ret.mgy.to_u64 + 2*M).to_u32!
            end
            ret
          end

          def -(value)
            self - self.class.new(value)
          end

          def -(value : self)
            ret = self.class.raw(@mgy)
            ret.mgy = (ret.mgy.to_i64 - value.mgy).to_u32!
            if ret.mgy.to_i32! < 0
              ret.mgy = (ret.mgy.to_u64 + 2*M).to_u32!
            end
            ret
          end

          def *(value)
            self * self.class.new(value)
          end

          def *(value : self)
            ret = self.class.raw(@mgy)
            ret.mgy = reduce(ret.mgy.to_u64 * value.mgy)
            ret
          end

          def /(value)
            self / self.class.new(value)
          end

          def /(value : self)
            self * value.inv
          end

          def //(value)
            self / value
          end

          def **(value)
            if value == 0
              return self.class.new(1)
            end

            if self.zero?
              self
            end

            b = value > 0 ? self : inv
            e = value.abs
            ret = self.class.new(1)
            while e > 0
              if e.odd?
                ret *= b
              end
              b *= b
              e >>= 1
            end
            ret
          end

          def <<(value)
            self * self.class.new(2) ** value
          end

          def sqrt
            z = self.class.new(1)
            until z ** ((M - 1) // 2) == M - 1
              z += 1
            end

            q = M - 1
            m = 0
            while q.even?
              q //= 2
              m += 1
            end

            c = z ** q
            t = self ** q
            r = self ** ((q + 1) // 2)
            m.downto(2) do |i|
              tmp = t ** (2 ** (i - 2))
              if tmp != 1
                r *= c
                t *= c ** 2
              end
              c *= c
            end

            if r * r == self
              r.to_i64 * 2 <= M ? r : -r
            else
              nil
            end
          end

          def inv
            x = value.to_i32
            y = M.to_i32
            u, v = 1, 0
            while y > 0
              t = x // y
              x -= t * y
              x, y = y, x
              u -= t * v
              u, v = v, u
            end
            self.class.new(u)
          end

          def to_i64
            value
          end

          def ==(other : self)
            value == other.value
          end

          def ==(other)
            value == other
          end

          def -
            self.class.new(0) - self
          end

          def +
            self
          end

          def abs
            value
          end

          def pred
            self - 1
          end

          def succ
            self + 1
          end

          def zero?
            value == 0
          end

          def pow(value : Int)
            self ** value
          end

          def <(value)
            raise NotImplementedError.new("<")
          end

          def <=(value)
            raise NotImplementedError.new("<=")
          end

          def >(value)
            raise NotImplementedError.new(">")
          end

          def >=(value)
            raise NotImplementedError.new(">=")
          end

          def to_s(io : IO)
            io << value
          end

          def inspect(io : IO)
            to_s(io)
          end

          def mgy=(v : UInt32)
            @mgy = v
          end

          @[AlwaysInline]
          def reduce(b : UInt64) : UInt32
            ((b + (b.to_u32!.to_u64 * MR).to_u32!.to_u64 * M) >> 32).to_u32
          end

          @[AlwaysInline]
          def value
            ret = reduce(@mgy.to_u64)
            ret >= M ? (ret - M).to_i64 : ret.to_i64
          end
        end
      {% else %}
        struct {{name}}
          MOD = {{modulo}}

          getter value : Int64

          def initialize(@value : Int64)
            @value %= MOD
          end

          def initialize(value)
            @value = value.to_i64 % MOD
          end

          @@factorials = Array(self).new

          def self.factorial(n)
            if @@factorials.empty?
              # Change the initial capacity of this array to improve performance
              @@factorials = Array(self).new(100_000_i64)
              @@factorials << self.new(1_i64)
            end
            @@factorials.size.upto(n) do |i|
              @@factorials << @@factorials.last * i
            end
            @@factorials[n]
          end

          def self.permutation(n, k)
            raise ArgumentError.new("k cannot be greater than n") unless n >= k
            factorial(n) // factorial(n - k)
          end

          def self.combination(n, k)
            raise ArgumentError.new("k cannot be greater than n") unless n >= k
            permutation(n, k) // @@factorials[k]
          end

          def self.repeated_combination(n, k)
            combination(n + k - 1, k)
          end

          def self.zero
            self.new(0_i64)
          end

          def clone
            self.class.new(@value)
          end

          def inv
            g, x = AtCoder::Math.extended_gcd(@value, MOD)
            self.class.new(x)
          end

          def +(value : self)
            self.class.new(@value + value.to_i64)
          end

          def +(value)
            self.class.new(@value + value.to_i64 % MOD)
          end

          def -(value : self)
            self.class.new(@value - value.to_i64)
          end

          def -(value)
            self.class.new(@value - value.to_i64 % MOD)
          end

          def *(value : self)
            self.class.new(@value * value.to_i64)
          end

          def *(value)
            self.class.new(@value * (value.to_i64 % MOD))
          end

          def /(value : self)
            raise DivisionByZeroError.new if value == 0
            self * value.inv
          end

          def /(value)
            raise DivisionByZeroError.new if value == 0
            self * self.class.new(value.to_i64).inv
          end

          def //(value)
            self./(value)
          end

          def **(value)
            self.class.new(AtCoder::Math.pow_mod(@value, value.to_i64, MOD))
          end

          def <<(value)
            self * self.class.new(2_i64) ** value
          end

          def sqrt
            z = self.class.new(1_i64)
            until z ** ((MOD - 1) // 2) == MOD - 1
              z += 1
            end
            q = MOD - 1
            m = 0
            while q % 2 == 0
              q //= 2
              m += 1
            end
            c = z ** q
            t = self ** q
            r = self ** ((q + 1) // 2)
            m.downto(2) do |i|
              tmp = t ** (2 ** (i - 2))
              if tmp != 1
                r *= c
                t *= c ** 2
              end
              c *= c
            end
            if r * r == self
              r.to_i64 * 2 <= MOD ? r : -r
            else
              nil
            end
          end

          def to_i64
            @value
          end

          def ==(value : self)
            @value == value.to_i64
          end

          def ==(value)
            @value == value
          end

          def -
            self.class.new(0_i64) - self
          end

          def +
            self
          end

          def abs
            self
          end

          def pred
            self.class.new(@value - 1)
          end

          def succ
            self.class.new(@value + 1)
          end

          def zero?
            @value == 0
          end

          # ac-library compatibility

          def pow(value)
            self.**(value)
          end

          def val
            self.to_i64
          end

          # ModInt shouldn't be compared

          def <(value)
            raise NotImplementedError.new("<")
          end
          def <=(value)
            raise NotImplementedError.new("<=")
          end
          def >(value)
            raise NotImplementedError.new(">")
          end
          def >=(value)
            raise NotImplementedError.new(">=")
          end

          delegate to_s, to: @value
          delegate inspect, to: @value
        end
      {% end %}

    end

    struct Int
      def +(value : AtCoder::{{name}})
        value + self
      end

      def -(value : AtCoder::{{name}})
        -value + self
      end

      def *(value : AtCoder::{{name}})
        value * self
      end

      def //(value : AtCoder::{{name}})
        value.inv * self
      end

      def /(value : AtCoder::{{name}})
        self // value
      end

      def ==(value : AtCoder::{{name}})
        value == self
      end
    end
  end
end

AtCoder.static_modint(ModInt1000000007, 1_000_000_007)
AtCoder.static_modint(ModInt998244353, 998_244_353)
AtCoder.static_modint(ModInt754974721, 754_974_721_i64)
AtCoder.static_modint(ModInt167772161, 167_772_161_i64)
AtCoder.static_modint(ModInt469762049, 469_762_049_i64)

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

alias Mint = AtCoder::ModInt998244353

n, m = ints
dp = [Mint.zero, Mint.new(m)]
(n - 1).times do |i|
  dp2 = [Mint.zero, Mint.zero]
  dp2[0] = dp[0] * Mint.new(m - 2) + dp[1] * Mint.new(m - 1)
  dp2[1] = dp[0]
  dp = dp2
end

puts dp[0]