n = int(input())
a = list(map(int, input().split()))
p = [(a[i], i + 1) for i in range(n)]
p.sort()
print(*[i for _, i in p])