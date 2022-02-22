# n! のうち、七五数は何個あるか
n = int(input())

# n! の素因数分解
table = [0] * (n + 1)
for i in range(1, n + 1):
   for j in range(2, i + 1):
      while i % j == 0:
         table[j] += 1
         i //= j

# 指数が l 以上 r 未満なのは何個？
INF = 10**9
def num(l, r=INF):
   res = 0
   for i in range(n + 1):
      if l <= table[i] < r:
         res += 1
   return res

# 組み合わせの計算
ans = 0
ans += (num(2, 4) * num(4) * (num(4) - 1) // 2) + (num(4)*(num(4) - 1)*(num(4) - 2) // 2)
ans += (num(2, 24) * num(24)) + (num(24) * (num(24) - 1))
ans += (num(4, 14) * num(14)) + (num(14) * (num(14) - 1))
ans += num(74)

print(ans)