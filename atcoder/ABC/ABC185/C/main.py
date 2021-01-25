from scipy.special import comb
L = int(input())
print(int(comb(L-1, 11, exact=True)))