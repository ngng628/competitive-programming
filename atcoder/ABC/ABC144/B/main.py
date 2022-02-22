memory = set(a*b for a in range(1, 10) for b in range(1, 10))
n = int(input())
print('Yes' if n in memory else 'No')