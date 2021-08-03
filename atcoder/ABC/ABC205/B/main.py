n = int(input())
print('Yes' if sorted(list(map(int, input().split()))) == list(range(1, n+1)) else 'No')
