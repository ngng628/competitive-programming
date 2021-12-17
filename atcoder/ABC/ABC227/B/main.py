import sys
input = sys.stdin.readline
N = int(input())
S = list(map(int, input().split()))

can = set([4*a*b + 3*a + 3*b for a in range(1, 1001) for b in range(1, 1001)])
ans = sum([not s in can for s in S])

print(ans)
