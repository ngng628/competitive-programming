# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

s = str

set = Set(Char).new
stack = Deque(Char).new
s.each_char do |c|
  case c
  when '('
    stack << c
  when ')'
    while stack[-1].ascii_letter?
      set.delete(stack[-1])
      stack.pop
    end
    stack.pop
  else
    (puts "No") + exit if set.includes?(c)
    set << c
    stack << c
  end
end

puts "Yes"