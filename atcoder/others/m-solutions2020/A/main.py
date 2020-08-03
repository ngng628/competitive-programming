x = int(input())

if 400 <= x and x <= 599:
    ans = 8
if 600 <= x and x <= 799:
    ans = 7
if 800 <= x and x <= 999:
    ans = 6
if 1000 <= x and x <= 1199:
    ans = 5
if 1200 <= x and x <= 1399:
    ans = 4
if 1400 <= x and x <= 1599:
    ans = 3
if 1600 <= x and x <= 1799:
    ans = 2
if 1800 <= x and x <= 1999:
    ans = 1

print(ans)
