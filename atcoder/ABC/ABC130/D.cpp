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

#define N_MAX (100000)

lint N, K;
vector<lint> a;
int sum_n[N_MAX + 1];

int main()
{
    cin >> N >> K;
    a.resize(N);
    rep (i, N) { cin >> a[i]; }

    sum_n[0] = 0;
    for (lint i = 1; i <= N; ++i)
    {
        sum_n[i] = sum_n[i-1] + a[i-1];
    }


    lint cnt = 0;
    for (lint i = 1; i <= N; ++i)
    {
        for (lint k = 0; k <= N; ++k)
        {   
            if (k < i)
            {
                break;
            }
            if (sum_n[k] - sum_n[i] >= K)
            {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
