# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define MSG(x) std::cout << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

static const lint mod7 = 1000000007;

lint Permutation(lint n, lint r)
{
    r = (n - r) % mod7;
    lint sum = 1;
    for (lint i = n; i >= r+1; --i)
    {
        sum = (sum * i) % mod7;
    }
    return sum;
}

lint kaijo(lint n)
{
    lint sum = 1;
    for (int i = 1; i <= n; ++i)
    {
        sum = (sum * i) % mod7;
    }
    return sum;
}

int main()
{
    lint N, K;
    cin >> N >> K;

    for (lint r = 1; r < K; ++r)
    {
        cout << Permutation(N - K + 1, r) % mod7 << endl;
    }

    // わからん!w
    cout << kaijo(N - 2*K + 1) % mod7 << endl;

    return 0;
}
