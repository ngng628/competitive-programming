hw = list(map(int, input().split()))
rc = list(map(int, input().split()))
ans = 4 - sum(rc[i] == hw[i] for i in [0, 1]) - sum(rc[i] == 1 for i in [0, 1])
print(ans)
