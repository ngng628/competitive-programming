S, L, R = map(int, input().split())

X = S
while not (L <= X and X <= R):
    if X < L:
        X += 1
    else:
        X += -1

print(X)
