H = 2000
W = 2000
Q = 100000
print(H, W)
print(Q)
for i in range(Q - 1):
   print(1, i // H + 1, i % H + 1)
print(2, 1, 1, H, W)