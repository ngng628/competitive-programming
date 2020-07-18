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
    int N;
    cin >> N;
    vector<lint> A(N);
    rep (i, N)
    {
        cin >> A[i];
    }

    int before = A[0];
    int cnt = 0;
    pair<int, lint> C[100001];
    for (int i = 1; i < N; ++i)
    {
        int now = A[i];
        if (now < before)
        {
            // now の値を今の色に代入
            C[i].second = now;
        }
        else
        {
            // 過去の色をたんさく
            // O(?)
            for (int k = 0; k < cnt; ++k)
            {

            }
        }
    }

    return 0;
}
