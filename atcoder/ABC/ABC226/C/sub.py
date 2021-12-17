import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

n = int(input())
l = [input().split() for _ in range(n)]
T = [int(l[i][0]) for i in range(n)]
a = [list(map(int, l[i][2:])) for i in range(n)]

mastered = [False] * n

def calc_duration(i):
   if mastered[i]:
      return 0

   total = T[i]
   for j in a[i]:
      total += calc_duration(j - 1)

   mastered[i] = True
   return total

print(calc_duration(n - 1))