S = input()[::-1]
dream = 'dream'[::-1]
dreamer = 'dreamer'[::-1]
erase = 'erase'[::-1]
eraser = 'eraser'[::-1]

flag = True
while flag or not len(S) == 0:
    print(S)
    flag = False
    if S[:7] == dreamer:
        S.replace(dreamer, '', 1)
        flag = True
    if S[:6] == eraser:
        S.replace(eraser, '', 1)
        flag = True
    if S[:5] == dream:
        S.replace(dream, '', 1)
        flag = True
    if S[:5] == erase:
        S.replace(erase, '', 1)
        flag = True

if len(S) == 0:
    print('YES')
else:
    print('NO')
