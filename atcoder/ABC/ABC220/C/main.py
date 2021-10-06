n = int(input())
a = list(map(int, input().split()))
x = int(input())

s = sum(a)

t = n * (x // s)
now = (x // s)*s
for i in range(n):
   t += 1
   now += a[i]
   if (now > x):
      break

print(t)