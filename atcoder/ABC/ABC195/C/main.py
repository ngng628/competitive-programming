n = int(input())
print(sum(max(0, n - pow(1000, i) + 1) for i in range(1, 6)))
