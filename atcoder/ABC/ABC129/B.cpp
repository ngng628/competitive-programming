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

int main()
{
    int N; cin >> N;
    vector<int> W(N);
    rep (i, N)
    {
        cin >> W[i];
    }

    int sum_W = 0;

    rep (i, N)
    {
        sum_W += W[i];
    }

    int before = sum_W;
    int sum_W_ = 0;
    int after = 100000000;
    int ans;
    rep (i, N)
    {
        before -= W[i];
        sum_W_ += W[i];
        if (abs(before - sum_W_) > after)
        {
            ans = std::min(abs(before - sum_W_), after);
            break;
        }
        after = abs(before - sum_W_);
    }

    cout << ans << endl;

    return 0;
}
