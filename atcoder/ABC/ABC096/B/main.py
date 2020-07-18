li = [ int(x) for x in input().split() ]
K = int(input())

li.sort()

print(li[0] + li[1] + li[2] * 2**K)
