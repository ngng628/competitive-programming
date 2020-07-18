N, K = map(int, input().split())

a = N // K

suj1 = abs(N - a*K)
suj2 = abs(N - (a+1)*K)

print(min(suj1, suj2))
