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
    vector<int> A(N);
    rep (i, N) { cin >> A[i]; }

    int m = 0;
    int mi = 0;
    for (int i = 0; i < N; ++i)
    {
        if (chmax(m, A[i]))
        {
            mi = i;
        }

    }

    A.erase(A.begin() + mi);
    int m2 = 0;
    int mi2 = 0;
    for (int i = 0; i < N-1; ++i)
    {
        if (chmax(m2, A[i]))
        {
            mi2 = i;
        }

    }
    

    for (int i = 0; i < N; ++i)
    {
        if (i == mi)
        {
            cout << m2 << endl;
        }
        else
        {
            cout << m << endl;
        }
    }



    return 0;
}
