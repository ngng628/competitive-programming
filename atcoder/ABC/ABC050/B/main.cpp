# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define all(x) (x).begin(), (x).end()
# define len(x) ((int)(x).size())
# define pb push_back
# define int long long
using namespace std;
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main()
{
    int N; cin >> N;
    vi T(N);
    rep (i, N) { cin >> T[i]; }
    int M; cin >> M;
    vi P(M);
    vi X(M);
    rep (i, M) { cin >> P[i] >> X[i]; }

    int sum = 0;
    rep (i, N) sum += T[i];

    rep (i, M) cout << sum - T[P[i] - 1] + X[i] << "\n";

    return 0;
}
