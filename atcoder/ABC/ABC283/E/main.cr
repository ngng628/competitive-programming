# 🎂🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁💝🎅🤶🎁🎂
def int(b = 0); read_line.to_i + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = 100100100
# 🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄⛄🏠🏠🏠⛄🎄


h, w = ints
a = (1..h).map{ ints + [-1] }

dp = (2...h).reduce([[OO, OO], [OO, OO]]) do |dp, i|
  dp2 = [[OO, OO], [OO, OO]]
  8.times.map{ |m| {m.bit(0), m.bit(1), m.bit(2)} }.each do |r1, r2, r3|
      d = a[i - 2].map{ |e| e ^ r3 }
      c = a[i - 1].map{ |e| e ^ r2 }
      b = a[i].map{ |e| e ^ r1 }
      
      ok = w.times.all?{ |j| c[j].in?({ d[j], c[j - 1], c[j + 1], b[j] }) }

      if i == 2
        ok &= w.times.all?{ |j| d[j].in?({ c[j], d[j - 1], d[j + 1] }) }
      end

      if i == h - 1
        ok &= w.times.all?{ |j| b[j].in?({ c[j], b[j - 1], b[j + 1] }) }
      end

      u = i == 2 ? r2 + r3 + r1 : dp[r2][r3] + r1
      chmin(dp2[r1][r2], u) if ok
  end
  dp2
end

ans = dp.min_of{ |e| e.min }
puts ans >= OO ? -1 : ans