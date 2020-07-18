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

    optimize_cin();
    int N, K;
    vector<string> D;
    cin >> N >> K;
    D.resize(K);
    rep (i, K) { cin >> D[i]; }

    for (int i = N; i < 10*N; ++i)
    {
        string ans = to_string(i);
        bool ok = false;
        for (int k = 0; k < SZ(D); ++k)
        {
            if (ans.find(D[k]) == -1) // 見つからなかったら
            {
                ok = true;
            }
            else
            {
                ok =false;
                break;
            }
        }

        if (ok)
        {
            cout << ans;
            break;
        }
    }

end:
    cout << "\n";

    return 0;
}
