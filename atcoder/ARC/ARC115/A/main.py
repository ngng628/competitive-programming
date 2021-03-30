n, m = map(int, input().split())
s = [input().count('0') % 2 for _ in range(n)]
print(s.count(0) * s.count(1))