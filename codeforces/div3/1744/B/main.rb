# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); gets.to_i + b end
def ints(b = 0); gets.split.map{ |x| x.to_i + b } end
def str; gets.chomp end
OO = (1<<62)-(1<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def solve
  n, q = ints
  a = ints
  n_evens = a.count(&:even?)
  n_odds = a.count(&:odd?)
  s = a.sum
  q.times do
    t, x = ints
    case t
    when 0
      s += n_evens * x
      puts s
      if x.odd?
        n_odds += n_evens
        n_evens = 0
      end
    when 1
      s += n_odds * x
      puts s
      if x.odd?
        n_evens += n_odds
        n_odds = 0
      end
    end
  end
end

t = int
t.times do
  solve
end