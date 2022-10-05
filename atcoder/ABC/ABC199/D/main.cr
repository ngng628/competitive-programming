# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
alias Pii = { Int64, Int64 }
def int; read_line.to_i64 end
def ints; read_line.split.map(&.to_i64) end
def int(offset : Int64); read_line.to_i64 + offset end
def ints(offset : Int64); read_line.split.map{ |x| x.to_i64 + offset} end
def str; read_line.chomp end
def min(a : Int64, b : Int64) : Int64; a < b ? a : b end
def max(a : Int64, b : Int64) : Int64; a > b ? a : b end
def argmin(v); v.index(v.min) || -1 end
def argmax(v); v.index(v.max) || -1 end
macro chmin(a, b); {{a}} = min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = min({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
DYDX4 = [ {1_i64, 0_i64}, {-1_i64, 0_i64}, {0_i64, 1_i64}, {0_i64, -1_i64} ]
DYDX8 = [ {1_i64, 0_i64}, {1_i64, 1_i64}, {0_i64, 1_i64}, {-1_i64, 1_i64},
          {-1_i64, 0_i64}, {-1_i64, -1_i64}, {0_i64, -1_i64}, {1_i64, -1_i64} ]
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

# 1. 入力
n, m = ints
graph = Array(Array(Int64)).new(n){ Array(Int64).new }
ut = DisjointSet.new(n)
m.times do
  u, v = ints -1
  graph[u] << v
  graph[v] << u
  ut.unite(u, v)
end

ans = ut.groups().not_nil!.reduce(1_i64) do |acc, group|
  if group.size == 1
    acc * 3
  else
    root = group[0]
  
    visited = Array.new(n){ |i| i == root ? true : false }
    indices = Array(Int64 | Nil).new(n){ nil }
    pre = Array.new(n, -1_i64)
    idx = 0_i64
    dfs = uninitialized Proc(Int64, Int64, Nil)
    dfs = ->(from : Int64, pre_idx : Int64) do
      indices[idx] = from
      pre[idx] = pre_idx
      idx += 1
      graph[from].each do |to|
        next if visited[to]
        visited[to] = true
        dfs.call(to, from)
      end
      nil
    end
    dfs.call(root, -1_i64)

    cnt = 0_i64
    colors = Array.new(n, -1_i64)
    dfs2 = uninitialized Proc(Int64, Nil)
    dfs2 = ->(i : Int64) do
      # 正しく塗られているか判定
      if i == idx
        ok = group.all? do |x|
          graph[x].all? do |y|
            colors[x] != colors[y]
          end
        end
        cnt += 1 if ok
        return nil
      end

      v = indices[i].not_nil!  
      (1_i64..3_i64).reject{ |c| colors[pre[i].not_nil!] == c }.each do |c|
        colors[v] = c
        dfs2.call(i + 1)
      end
      nil
    end

    colors[root] = 1_i64
    dfs2.call(1_i64)

    acc * (cnt * 3)
  end
end

puts ans


class DisjointSet
  @n : Int64
  @parent_or_size : Array(Int64)

  def initialize
    @n = 0
    @parent_or_size = Array(Int64).new
  end

  def initialize(@n : Int64)
    @parent_or_size = Array(Int64).new(n, -1_i64)
  end

  def unite(a : Int64, b : Int64) : Int64
    x = leader(a)
    y = leader(b)
    return x.to_i64 if x == y
    if -@parent_or_size[x] < -@parent_or_size[y]
      x, y = y, x
    end
    @parent_or_size[x] += @parent_or_size[y]
    @parent_or_size[y] = x
    x.to_i64
  end

  def equiv?(a : Int64, b : Int64) : Bool
    leader(a) == leader(b)
  end

  def leader(a : Int64) : Int64
    return a.to_i64 if @parent_or_size[a] < 0
    @parent_or_size[a] = leader(@parent_or_size[a])
    @parent_or_size[a].to_i64
  end

  def size(a : Int64) : Int64
    -@parent_or_size[leader(a)].to_i64
  end

  def groups : Array(Array(Int64)) | Nil
    leader_buf = Array(Int64).new(@n, 0_i64)
    group_size = Array(Int64).new(@n, 0_i64)
    @n.times do |i|
      leader_buf[i] = leader(i)
      group_size[leader_buf[i]] += 1
    end
    res = Array.new(@n){ Array(Int64).new() }
    @n.times do |i|
      res[leader_buf[i]] << i.to_i64
    end
    res.delete([] of Int64)
    res
  end
end