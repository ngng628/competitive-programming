n = int(input())
p = list(map(int, input().split()))
s = sum(i + 1 != p[i] for i in range(n))
print('YES' if s == 0 or s == 2 else 'NO')
