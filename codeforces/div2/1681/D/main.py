from collections import deque as Queue

n, x = map(int, input().split())

ans = 10**18
que = Queue()
que.append((str(x), 0))
st = set()
while que:
   now, cnt = que.pop()
   if len(now) == n:
      ans = cnt
      break

   for c in ''.join(set(now)):
      nxt = str(int(now) * int(c))
      if (len(nxt) > n):
         continue
      if int(nxt) in st:
         continue
      que.appendleft((nxt, cnt + 1))
      st.add(int(nxt))

print('-1' if ans == 10**18 else ans)