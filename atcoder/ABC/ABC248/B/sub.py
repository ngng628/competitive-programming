import math
a, b, k = map(int, input().split())
print(math.ceil(math.log(b / a, k)))