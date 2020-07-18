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

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N-1);
    rep (i, N)
    {
        cin >> A[i];
        A[i]--;
    }
    rep (i, N)
    {
        cin >> B[i];
    }
    rep (i, N-1)
    {
        cin >> C[i];
    }


    lint ans = 0;
    int before = -1;
    for (int i = 0; i < N; ++i)
    {
        ans += B[A[i]];
        if (before+1 == A[i] && C.size() >= before)
        {
            ans += C[before];
        }
        before = A[i];
    }

    cout << ans << endl;

    return 0;
}
