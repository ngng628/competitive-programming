///----------------------------------
/// 樹木にとって最も大切なものは何かと問うたら、
/// それは果実だと誰もが答えるだろう。
/// しかし実際には種なのだ。
/// 
/// - ニーチェ -
///----------------------------------
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

int N;
vector<double> v;

int main()
{
    cin >> N;
    v.resize(N);
    rep (i, N) { cin >> v[i]; }

    sort(ALL(v));

    double ans = (v[0] + v[1]) / 2.0;

    for (int i = 2; i < N; ++i)
    {
        ans = (ans + v[i]) / 2.0;
    }

    cout << ans << endl;

    return 0;
}
