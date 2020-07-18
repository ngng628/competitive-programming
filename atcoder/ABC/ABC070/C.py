def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd (a, b)		

N = int(input())
T = []
ans = int(input())
for _ in range(N-1):
    t = int(input())
    ans = lcm(ans, t)

print(ans)


