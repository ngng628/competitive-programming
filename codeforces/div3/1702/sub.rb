n = gets.to_i
graph = Array.new(n){ Array.new }
(n - 1).times do
  u, v = gets.split.map{ |x| x.to_i - 1 }
  graph[u].push(v)
  graph[v].push(u)
end

not_visited = 10**9
dist = Array.new(n, not_visited)
que = Deque.new
que.push(0)
dist[0] = 0
until que.empty?
  from = que.pop
  graph[from].filter{ |to| dist[to] == not_visited }.each do |to|
    dist[to] = dist[from] + 1
    que.push(to)
  end
end

q = gets.to_i
q.times do
  k = gets.to_i
  a = gets.split.map{ |x| x.to_i - 1 }.sort_by{ |i, j| -dist[i] <=> -dist[j] }
  
  # 1回目
  deepest = a[0]
  

end