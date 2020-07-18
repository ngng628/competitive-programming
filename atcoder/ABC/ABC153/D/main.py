H = int(input())

cnt = 0
index = 0

while H > 0:
    H //= 2
    cnt += 2**index
    index += 1

print(cnt)
