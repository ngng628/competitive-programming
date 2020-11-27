import heapq
from collections import deque
from enum import Enum
import sys
import math
from _heapq import heappush, heappop
import copy

BIG_NUM = 2000000000
MOD = 1000000007
EPS = 0.000000001


class Edge:
    def __init__(self,arg_to,arg_dist):
        self.to = arg_to
        self.dist = arg_dist


_N = int(input())
V = _N
E = _N*(_N - 1) // 2

POW = [None]*(V+1)
POW[0] = 1
for i in range(1,V+1):
    POW[i] = POW[i-1]*2

G = [[] for _ in range(V)]

li = []
for _ in range(_N):
    x, y, z = map(int, input().split())
    li.append([x, y, z])

for i in range(_N):
    for k in range(i + 1, _N):
        p, q = li[i], li[k]
        from_ = i
        to_ = k
        dist = abs(p[0] - q[0]) + abs(p[1] - q[1]) + max(0, q[2] - p[2])
        G[from_].append(Edge(to_, dist))
        G[to_].append(Edge(from_, dist))


#経路は輪になるので、スタートは0として良い
start = 0
dp = [[BIG_NUM]*V for _ in range(POW[V])]

dp[POW[start]][start] = 0

for state in range(1,POW[V]):
    for last_node in range(V):
        if dp[state][last_node] == BIG_NUM:
            continue
        for edge in G[last_node]:
            if state & POW[edge.to] != 0:
                continue #訪問済
            next_state = state+POW[edge.to]
            if dp[next_state][edge.to] > dp[state][last_node]+edge.dist:
                dp[next_state][edge.to] = dp[state][last_node]+edge.dist

ans = BIG_NUM
#startに戻る
for last_node in range(V):
    if dp[POW[V]-1][last_node] == BIG_NUM:
        continue
    for edge in G[last_node]:
        if edge.to != start:
            continue
        ans = min(ans,dp[POW[V]-1][last_node]+edge.dist)

if ans == BIG_NUM:
    print("-1")
else:
    print("%d"%(ans))

