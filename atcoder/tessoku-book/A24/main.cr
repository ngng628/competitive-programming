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
puts a.lis(strict: true)

class Array(T)
  # 最長増加部分列の長さを返します。
  #
  # `strict が `true` の場合、狭義単調増加として考えます。
  #
  # ```
  # [1, 9, 1, 2, 3, 8].lis(strict: true) # => 3
  # [1, 9, 1, 2, 3, 8].lis(strict: false) # => 4
  # ```
  def lis(strict : Bool) : Int64
    dp = Array(T).new
    each do |v|
      i = dp.bsearch_index{ |e| strict ? e >= v : e > v }
      if i.nil?
        dp << v
      else
        dp[i.not_nil!] = v
      end
    end
    dp.size.to_i64
  end
end