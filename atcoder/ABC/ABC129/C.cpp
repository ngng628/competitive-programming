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
#define MOD7 (1000000007)

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    rep (i, M) { cin >> a[i]; }

    int cnt = 0;
    int start = 0;
    int A = 0;
    for (int i = 0; i < M; ++i)
    {
        if (i+1 < M && a[i+1] - a[i])
        {
            cout << 0 << endl;
            return 0;
        }
        A = a[i] - start;

        if (A&1) // 奇数
        {
            cnt += A / 2;
            start = a[i] + 1;
        }
        else // 偶数
        {
            cnt += A / 2 - 1;
            start = a[i] + 1;
        }
    }

    A = N - start;
    cnt += A / 2;

    cout << (cnt*2) % MOD7 << endl;

    return 0;
}
