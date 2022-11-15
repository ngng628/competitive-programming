# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); gets.to_i + b end
def ints(b = 0); gets.split.map{ |x| x.to_i + b } end
def str; gets.chomp end
OO = (1<<62)-(1<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

def solve
  n = int
  a = ints
  s = str

  b = [-1] * n
  t = "?" * n
  n.times do |i|
    unless a[i] == nil
      # a[i] -> s[i]
      n.times do |j|
        if a[j] == a[i]
          return false if t[j] != '?' && t[j] != s[i]
          t[j] = s[i]
        end
      end
    end
  end

  s == t
end

t = int
t.times do
  ans = solve
  puts ans ? "YES" : "NO"
end