# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
using namespace std;
using lint = long long;
template<class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;
static const lint N_MAX = (lint)5 * 1e3;

lint N;
string s, t;

lint dp[N_MAX+1][N_MAX+1];

void solve()
{
    for (int i = 0; i < N; ++i)
    {
        for (int k = 0; k < N; ++k)
        {
            debug(s[i]);
            debug(t[i]);
            if (s[i] == t[k] && !(i <= k))
            {
                dp[i+1][k+1] = dp[i][k] + 1;
            }
            else
            {
                dp[i+1][k+1] = max(dp[i][k+1], dp[i+1][k]);
            }
        }
    }
}

int main()
{
    cin >> N;
    cin >> s;
    t = s;

    reps (i, N_MAX)
    {
        reps (k, N_MAX)
        {
            dp[k][i] = 0;
        }
    }

    solve();


    cout << dp[N-1][N-1] << endl;

    return 0;
}
