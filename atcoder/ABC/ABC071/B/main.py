S = input()
origin = set()
for i in range(26):
    origin.add(chr(ord('a') + i))

s = set(S)
li = list(origin - s)
if len(li) == 0:
    print('None')
else:
    print(sorted(li)[0])


