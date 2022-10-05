# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．
def int(b = 0); read_line.to_i64 + b end
def ints(b = 0); read_line.split.map{ |x| x.to_i64 + b } end
def str; read_line.chomp end
macro chmin(a, b); {{a}} = Math.min({{a}}, {{b}}) end
macro chmax(a, b); {{a}} = Math.max({{a}}, {{b}}) end
OO = (1_i64<<62)-(1_i64<<31)
# ○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．○。．

n, k = ints
# dp[i][j] = 山に i 個残っているときの「高橋 マイナス 青木」スコアの最大値
a = ints

strategy = Array.new(n + 1){ Array.new(n + 1){ 0_i64 } }
cache = Array(Array(Int64?)).new(n + 1){ Array(Int64?).new(2){ nil } }
dfs = uninitialized Proc(Int64, Int64, Int64)
ans = 0
dfs = ->(yama : Int64, turn : Int64) do
  return cache[yama][turn.even? ? 0 : 1].not_nil! if !cache[yama][turn.even? ? 0 : 1].nil?
  return 0_i64 if yama == 0_i64

  res = (turn.even? ? -OO : OO)
  a.each do |ai|
    if yama - ai >= 0_i64
      if turn.even?  # 高橋くんのターン
        score = dfs.call(yama - ai, turn + 1) + ai
        if res <= score
          res = score
          strategy[yama][turn] = ai
        end
      else
        score = dfs.call(yama - ai, turn + 1) - ai
        if res >= score
          res = score
          strategy[yama][turn] = ai
        end
      end
    end
  end

  cache[yama][turn.even? ? 0 : 1] = res
  res
end

dfs.call(n, 0_i64)

ans = 0
now = n
turn = 0
until now == 0
  puts "山 = #{now}, ターン = #{turn}"
  if turn.even?
    s = strategy[now][turn]
    ans += s
  else
    s = strategy[now][turn]
  end
  puts "s = #{s}"
  now -= s
  turn += 1
end

puts ans