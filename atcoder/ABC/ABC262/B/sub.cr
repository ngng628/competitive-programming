n, m = read_line.split.map(&.to_i)
mat = Matrix.new Array.new(n){ [0_i64] * n }
m.times do
  u, v = read_line.split.map{ |x| x.to_i - 1 }
  mat[u, v] = mat[v, u] = 1_i64
end

puts (mat**3).tr // 6

class Matrix(T)
  include Enumerable(T)

  class DimensionError < Exception
    def initialize(message = "Dimension Error.")
      super(message)
    end

    def initialize(h, w)
      super("Dimension Error: #{h}x#{w}.")
    end

    def initialize(h1, w1, h2, w2)
      super("Dimension Error: (#{h1}x#{w1}) (#{h2}x#{w2}).")
    end
  end

  getter m : Array(T)
  @n_rows : Int32
  @n_cols : Int32

  def column_size; @n_cols end
  def row_size; @n_rows end
  def size; {@n_rows, @n_cols} end

  def initialize
    @m = Array(T).new
    @n_rows, @n_cols = 0, 0
  end

  def initialize(h : Int, w : Int)
    @m = Array.new(h * w){ T.zero }
    @n_rows, @n_cols = h.to_i, w.to_i
  end

  def initialize(h : Int, w : Int, val : T)
    @m = Array.new(h * w){ val }
    @n_rows, @n_cols = h.to_i, w.to_i
  end

  def initialize(ary : Array(Array(T)))
    ArgumentError.new("ary.size must be greater than or equal to 1") if ary.size <= 0
    @n_rows, @n_cols = ary.size, ary[0].size
    @m = Array.new(@n_rows * @n_cols){ T.zero }
    ary.each_with_index do |v, i|
      v.each_with_index do |x, j|
        @m[@n_cols * i + j] = x
      end
    end
  end

  def self.new(h : Int, w : Int, &block : Int32, Int32 -> T)
    Matrix(T).new(h, w).tap do |mat|
      i, j = 0, 0
      (mat.column_size * mat.row_size).times do |index|
        mat[index] = yield i, j
        j += 1
        if i == h
          i = 0
          j += 1
        end
        if j == w
          i += 1
          j = 0
        end
      end
    end
  end

  def self.zero(h : Int, w : Int)
    new h, w, T.zero
  end

  def self.identity(h : Int, w : Int)
    raise DimensionError.new(h, w) if h != w
    Matrix(T).new(h, w) do |i, j|
      i == j ? T.new(1_i64) : T.zero
    end
  end

  def clone
    Matrix(T).new(@n_rows, @n_cols) do |i, j|
      at(i, j).clone
    end
  end

  def at(i : Int, j : Int) : T
    i += @n_rows if i < 0
    j += @n_cols if j < 0
    IndexError.new if over(i, j)
    @m[@n_cols * i + j]
  end

  def at?(i : Int, j : Int) : T?
    i += @n_rows if i < 0
    j += @n_cols if j < 0
    over(i, j) ? nil : @m[@n_cols * i + j]
  end

  def [](i : Int, j : Int) : T; at(i, j) end
  def []?(i : Int, j : Int) : T?; at?(i, j) end

  def at(index : Int) : T; @m[index] end
  def at?(index : Int) : T?; @m[index]? end
  def [](index : Int) : T; at(index) end
  def []?(index : Int) : T; at?(index) end

  def []=(i : Int, j : Int, val : T) : T
    i += @n_rows if i < 0
    j += @n_cols if j < 0
    IndexError.new if over(i, j)
    @m[@n_cols * i + j] = val
  end

  def []=(index : Int, val : T) : T
    @m[index] = val
  end

  def each(& : T ->)
    @m.each{ |x| yield x }
  end

  def each_with_index(& : T, {Int32, Int32} ->)
    @n_rows.times do |i|
      @n_cols.times do |j|
        yield @m[@n_cols * i + j], {i, j}
      end
    end
  end

  def push_row(v : Array(T))
    raise DimensionError.new(@n_row, @n_cols) if @n_cols != v.size
    @m.concat(v)
    @n_cols += 1
  end

  def push_col(v : Array(T))
    raise NotImplementedError.new
  end

  {% for op in %i(+ - ^ | &) %}
    def {{ op.id }}(other : Matrix(U)) forall U
      raise DimensionError.new(@n_rows, @n_cols, other.row_size, other.column_size) unless @n_rows == other.row_size && @n_cols == other.column_size
      res = Matrix(T | U).new(@n_rows, @n_cols)
      (@n_rows * @n_cols).times{ |i| res[i] = at(i) {{ op.id }} other.at(i) }
      res
    end
  {% end %}
  
  def *(other : Matrix(U)) forall U
    r0 = @n_rows
    c = @n_cols
    c0 = other.column_size
    raise DimensionError.new(r0, c, other.row_size, c0) if c != other.row_size
    res = Matrix(T | U).new(r0, c0)
    r0.times do |i|
      c.times do |k|
        c0.times do |j|
          res[i, j] += at(i, k) * other.at(k, j)
        end
      end
    end
    res
  end

  def /(other : Matrix(U)) forall U
    self * other.inv
  end

  {% for op in %i(* / //) %}
    def {{ op.id }}(k : T)
      res = Matrix(T).new(@n_rows, @n_cols)
      (@n_rows * @n_cols).times do |index|
        res[index] = at(index) {{ op.id }} k
      end
      res
    end
  {% end %}

  {% for op in %i(+ -) %}
    def {{ op.id }}(k : T)
      res = Matrix(T).new(@n_rows, @n_cols)
      (@n_rows * @n_cols).times do |index|
        res[index] = {{ op.id }} at(index)
      end
      res
    end
  {% end %}

  def **(k : Int); pow(k) end

  def pow(k : Int)
    if k < -1
      inv.pow(k.abs)
    elsif k == -1
      inv
    elsif k == 0
      Matrix(T).identity(@n_rows, @n_cols)
    elsif k == 1
      clone
    else
      pow_impl(k)
    end
  end

  private def pow_impl(k : Int)
    res = Matrix(T).identity(@n_rows, @n_cols)
    a = clone
    until k == 0
      res *= a if k.odd?
      a *= a
      k >>= 1
    end
    res
  end

  def det : T
    raise DimensionError.new(@n_rows, @n_cols) if @n_cols != @n_cols
    n = @n_rows
    case n
    when 1
      at(0, 0)
    when 2
      at(0, 0) * at(0, 2) - at(0, 1) * at(1, 0)
    else
      # TODO: study performance
      ary = to_a
      res = T.new(1_i64)
      n.times do |i|
        idx = -1
        (i...n).reverse_each do |j|
          unless ary[j][i].zero?
            idx = j
            break
          end
        end
        return T.zero if idx == -1
        if i != idx
          res = -res
          ary.swap(i, idx)
        end
        res *= ary[i][i]
        v = ary[i][i]

        n.times do |j|
          if v.is_a? Float
            ary[i][j] /= v
          else
            ary[i][j] //= v
          end
        end

        (i + 1...n).each do |j|
          a = ary[j][i]
          n.times do |k|
            ary[j][k] -= ary[i][k] * a
          end
        end
      end
      res
    end
  end

  def det?
    return nil if @n_cols != @n_cols
    det
  end

  def inv : Matrix(T)
    raise DimensionError.new(@n_rows, @n_cols) if @n_rows != @n_cols
    ary = to_a
    n = @n_rows
    res = Array.new(n){ |i| Array(T).new(n){ |j| i == j ? T.new(1_i64) : T.new(0_i64) }}
    rank = 0
    n.times do |j|
      # TODO: language update
      pivot = -1
      mx = T.zero
      (rank...n).each do |i|
        if mx < ary[i][j].abs
          mx = ary[i][j].abs
          pivot = i
        end
      end
      next if pivot == -1

      ary.swap(pivot, rank)
      res.swap(pivot, rank)

      fac = ary[rank][j]
      n.times do |k|
        if fac.is_a? Float
          ary[rank][k] /= fac
          res[rank][k] /= fac
        else
          ary[rank][k] //= fac
          res[rank][k] //= fac
        end
      end

      n.times do |i|
        if i != rank && ary[i][j].abs > T.zero
          fac = ary[i][j]
          n.times do |k|
            ary[i][k] -= ary[rank][k] * fac
            res[i][k] -= res[rank][k] * fac
          end
        end
      end
      rank += 1
    end
    Matrix(T).new res
  end

  def inv?
    return nil unless is_regular?
    inv
  end

  def tr : T
    raise DimensionError.new(@n_rows, @n_cols) if @n_rows != @n_cols
    n = @n_rows
    n.times.sum{ |i| at(i, i) }
  end

  def tr?
    return nil if @n_rows != @n_cols
    tr
  end

  def sweep(extended? : Bool = false) : Int32
    ary = to_a
    h, w = @n_rows, @n_cols
    rank = 0
    w.times do |j|
      break if extended? && j == w - 1

      # TODO: language update
      pivot = -1
      mx = T.zero
      (rank...h).each do |i|
        if mx < ary[i][j].abs
          mx = ary[i][j].abs
          pivot = i
        end
      end
      next if pivot == -1

      ary.swap(pivot, rank)

      fac = ary[rank][j]
      
      w.times do |k|
        if fac.is_a? Float
          ary[rank][k] /= fac
        else
          ary[rank][k] //= fac
        end
      end

      h.times do |i|
        if i != rank && ary[i][j].abs > T.zero
          fac = ary[i][j]
          w.times{ |k| ary[i][k] -= ary[rank][k] * fac }
        end
      end
      rank += 1
    end

    h.times{ |i| w.times{ |j| @m[@n_cols * i + j] = ary[i][j] } }

    rank
  end

  def zero? : Bool
    all?{ |x| x == T.zero }
  end

  def is_square?
    @n_rows == @n_cols
  end

  def is_regular?
    det != T.zero
  end

  def to_a : Array(Array(T))
    @n_rows.times.map do |i|
      @n_cols.times.map do |j|
        at(i, j)
      end.to_a
    end.to_a
  end

  def to_s(io : IO)
    w = @m.max_of{ |a| a.to_s.size }
    io << "Matrix(["
    @n_rows.times do |i|
      io << " " * 8 if i != 0
      io << "["
      @n_cols.times do |j|
        io << ", " if j != 0
        io << printf("%#{w}s", at(i, j).to_s)
      end
      io << "]"
      io << ")" if i == @n_rows - 1
      io << "\n" if i < @n_rows - 1
    end
  end

  def inspect(io : IO); to_s(io) end

  private def over(i : Int, j : Int)
    i < 0 || i >= @n_rows || j < 0 || j >= @n_cols
  end
end

struct Int
  def *(mat : Matrix(T))
    Matrix.new(mat.row_size, mat.column_size) do |i, j|
      self * mat[i, j]
    end
  end
end