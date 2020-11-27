h, w = map(int, input().split())
S = [input() for _ in range(h)]
cnt = 0
for i in range(len(S)):
    for k in range(len(S[i]) - 1):
        if S[i][k] == '.' and S[i][k + 1] == '.':
            cnt += 1
for i in range(len(S) - 1):
    for k in range(len(S[i])):
        if S[i][k] == '.' and S[i + 1][k] == '.':
            cnt += 1

print(cnt)

