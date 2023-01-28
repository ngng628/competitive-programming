# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

sc = FastIn::Scanner.new
n = sc.read_i32
a = (1..n).map{ sc.read_word }

half = (n + 1) // 2
agree = a.count("For")
ans = agree >= half
puts ans ? "Yes" : "No"









module FastIn
  extend self

  lib LibC
    fun getchar = getchar_unlocked : Char
  end

  class Scanner
    {% for int_t in Int::Primitive.union_types %}
      {% if Int::Signed.union_types.includes?(int_t) %}
      def read_{{ int_t.name.downcase[0..0] }}{{ int_t.name.downcase[3...int_t.name.size] }}(offset = 0)
      {% else %}
      def read_{{ int_t.name.downcase[0..0] }}{{ int_t.name.downcase[4...int_t.name.size] }}(offset = 0)
      {% end %}
        c = next_char
        res = {{ int_t }}.new(c.ord - '0'.ord)
        sgn = 1

        case c
        when '-'
          res = {{ int_t }}.new(LibC.getchar.ord - '0'.ord)
          sgn = -1
        when '+'
          res = {{ int_t }}.new(LibC.getchar.ord - '0'.ord)
        end

        until (c = LibC.getchar).ascii_whitespace?
          res = res*10 + (c.ord - '0'.ord)
        end

        res * sgn + offset
      end
    {% end %}

    def read_char : Char
      next_char
    end

    def read_word : String
      c = next_char
      s = [c]
      until (c = LibC.getchar).ascii_whitespace?
        s << c
      end
      s.join
    end

    private def next_char : Char
      c = '_'
      while (c = LibC.getchar).ascii_whitespace?
      end
      c
    end
  end
end
