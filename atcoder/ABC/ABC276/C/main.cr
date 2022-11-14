# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n = int
a = ints
puts a.prev_permutation!.not_nil!.join(" ")

class Array(T)
  def next_permutation!
    return nil if self.empty?

    prev = self.last
    i = self.rindex{ |v| v < prev || (prev = v; false) }

    unless i
      self.reverse!
      return nil
    end

    key = self[i]
    j = self.rindex{ |v| v > key }.not_nil!
    self.swap(i, j)
    self[i+1..-1] = self[i+1..-1].reverse!
    return self
  end

  def prev_permutation!
    return nil if self.empty?

    prev = self.last
    i = self.rindex{ |v| v > prev || (prev = v; false) }

    unless i
      self.reverse!
      return nil
    end

    key = self[i]
    j = self.rindex{ |v| v < key }.not_nil!
    self.swap(i, j)
    self[i+1..-1] = self[i+1..-1].reverse!
    return self
  end
end