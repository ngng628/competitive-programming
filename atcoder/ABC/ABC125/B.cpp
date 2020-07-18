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
    vector<int> V(N);
    rep (i, N)
    {
        cin >> V[i];
    }
    vector<int> C(N);
    rep (i, N)
    {
        cin >> C[i];
    }

    int sum = 0;
    rep (i, N)
    {
        if (V[i] - C[i] <= 0)
        {
            continue;
        }
        sum += V[i] - C[i];
    }

    cout << sum << endl;

    return 0;
}
