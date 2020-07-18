ans = 0
for i in range(1, 11):
    with open('test/sample' + str(i) + '.out') as f:
        s = f.read()
        ans += 10**6 + int(s)

print(ans * 5)
