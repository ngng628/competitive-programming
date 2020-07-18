A, B, C, X, Y = map(int, input().split())
AB = C

ans = 0
if 2*AB < A+B:
    if X < Y:
        ans += 2*AB * X
        Y -= X
        if 2*AB < B:
            ans += 2*AB * Y
        else:
            ans += B*Y
    else:
        ans += 2*AB * Y
        X -= Y
        if 2*AB < A:
            ans += 2*AB * X
        else:
            ans += A*X
else:
    ans = A*X + B*Y

print(ans)
