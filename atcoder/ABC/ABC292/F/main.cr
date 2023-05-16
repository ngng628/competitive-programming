# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmax(a, b); ({{a}} < {{b}} && ({{a}} = {{b}})) end
macro chmin(a, b); ({{a}} > {{b}} && ({{a}} = {{b}})) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def rad(deg)
  Math::PI * deg / 180
end

def bisect(ac : Float64, wa : Float64, error : Float64, & : Float64 -> Bool)
  n_iters = Math.log((wa - ac).abs / error, 2).to_i + 2
  n_iters.times do
    wj = (ac + wa) / 2
    if yield wj
      ac = wj
    else
      wa = wj
    end
  end
  ac
end

a, b = ints
if a > b
  a, b = b, a
end

# 一辺の長さを length にできますか？
ans = bisect(a.to_f, b.to_f + 1, error: 1e-9) { |length|
  cosθ = a / length
  next false unless 0 <= Math.acos(cosθ) && Math.acos(cosθ) <= rad(90)
  l1 = a.to_f * Math.tan( Math.acos(cosθ) )
  bottom = length * Math.cos( rad(60) - Math.acos(cosθ) ).abs
  l2 = length * Math.sin( rad(60) - Math.acos(cosθ) )
  bottom <= a && l1 + l2 <= b
}

printf("%.10f\n", ans)
