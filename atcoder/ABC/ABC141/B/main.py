s = input()
n = len(s)
odd = sum(s[i] == 'L' for i in range(0, n, 2))
even = sum(s[i] == 'R' for i in range(1, n, 2))
print('Yes' if odd + even == 0 else 'No')