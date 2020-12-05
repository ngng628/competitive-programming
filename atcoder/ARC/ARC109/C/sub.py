# >>> janken 
def janken(a, b):
  if a == 'R':
    if   b == 'R': return 0
    elif b == 'S': return 0
    elif b == 'P': return 1
  if a == 'S':
    if   b == 'R': return 1
    elif b == 'S': return 0
    elif b == 'P': return 0
  if a == 'P':
    if   b == 'R': return 0
    elif b == 'S': return 1
    elif b == 'P': return 0
# <<<

def solve(n, k, s):
  res = ''
  pow2k = pow(2, k)
  for i in range(0, min(2*n, pow2k), 2):
    a = s[i % n]
    b = s[(i + 1)%n]
    winner = janken(a, b)
    hand = a if winner == 0 else b
    res += hand
  return len(res), k - 1, res

n, k = map(int, input().split())
s = input()
while True:
  n, k, s = solve(n, k, s)
  if n == 1:
    break

print(s)

