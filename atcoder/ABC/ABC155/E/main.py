N = input()

ans = 0
flag = False
for i in range(len(N)):
    now = int(N[i])
    if flag == True:
        if 5 <= now and now <= 9:
            ans -= 1
    if 1 <= now and now <= 5:
        ans += now
    elif 6 <= now and now <= 9:
        if flag == True:
            ans += 10 - now
        else:
            ans += 1 + 10 - now
            flag = True
        

print(ans)
