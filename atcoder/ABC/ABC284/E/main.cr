# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

LIM = 10_i64**6

n, m = ints
graph = Array.new(n){ [] of Int64 }
m.times do
  u, v = ints -1
  graph[u] << v
  graph[v] << u
end

dfs = uninitialized Int64, Set(Int64) -> Nil
closed = [false] * n
memo = [0_i64] * n

ans = 0_i64
set = Set(Int64).new
dfs = ->(from : Int64, st : Set(Int64)) do
  ans += 1
  return if ans >= LIM
  set << from
  graph[from].each do |to|
    next if st.includes?(to)
    # st << to
    dfs.call(to, st)
    # st.delete(to)
    return if ans >= LIM
  end
  st.delete(from)
end

dfs.call(0_i64, set)
puts ans