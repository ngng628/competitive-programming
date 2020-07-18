# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int N, M; cin >> N >> M;
    vector<int> X(M);
    rep (i, M) { cin >> X[i]; }

    if (N >= M)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(ALL(X));
    vector<int> L;
    rep (i, M - 1)
    {
        L.push_back(abs(X[i] - X[i+1]));
    }
    sort(L.begin(), L.end());

    int s = 0;
    for (int i = 0; i < L.size() - N + 1; ++i)
    {
        s += L[i];
    }
    cout << s << endl;



    return 0;
}
