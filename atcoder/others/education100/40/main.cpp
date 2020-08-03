# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;

static const int T_MAX = 3;
static const int N_MAX = 100;
static const int D_MAX = 3;

int dp[N_MAX + 1][T_MAX + 1][T_MAX + 1];

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> B(N);
    rep (i, N) {
        int a, b;
        cin >> a >> b;
        B[a-1] = b-1;
    }

    for (int i = 0; i < N_MAX; ++i)
    {
        for (int a = 0; a <= 2; ++a)
        {
            for (int b = 0; b <= 2; ++b)
            {

            }
        }
    }

    return 0;
}
