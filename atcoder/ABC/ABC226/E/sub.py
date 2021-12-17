from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
   u, v = map(lambda x: int(x) - 1, input().split())
   graph[u].append(v)
   graph[v].append(u)

visited = [False] * n
ok = True
cnt = 0
for i in range(n):
   if visited[i]:
      continue
   edges = set()
   nodes = set()

   que = deque()
   que.append(i)
   visited[i] = True
   while que:
      now = que.popleft()
      nodes.add(now)
      for nxt in graph[now]:
         edges.add((now, nxt))
         edges.add((nxt, now))
         if visited[nxt]:
            continue
         visited[nxt] = True
         que.append(nxt)

   if len(edges) != 2*len(nodes):
      ok = False
      break
   cnt += 1

if ok:
   print(pow(2, cnt, 998_244_353))
else:
   print(0)