N, K = map(int, input().split())

if (N < K):
    sum = 0.0
    log2K = log2(K)
    for i in range(1, N):
        sum += pow(0.5, log2K - log2(i))

    sum /= N;
    print(sum);
else:
    sum = 0.0
    log2K = log2(K)
    for i in range(1, K - 1):
        sum += pow(0.5, log2K - log2(i))
    sum /= N;
    sum += (N - K + 1) / N;
    print(sum)
