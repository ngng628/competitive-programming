import random as rnd
n = int(input('[>] n : '))
print(n)
s = []
for i in range(n):
    li = [0]*n
    for k in range(n):
        li[k] = rnd.randint(0, 1)
    a = ''
    for l in li:
        a += str(l)
    print(a)
