from math import gcd
def lcm(a,b):
  return a//gcd(a,b)*b

a, b = map(int, input().split())
ans = lcm(a, b);
print(ans if ans <= 10**18 else 'Large')