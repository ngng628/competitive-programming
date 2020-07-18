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

bool distance(vector<int> y, vector<int> z)
{
    int sum = 0;
    rep (i, SZ(y))
    {
        sum += (y[i] - z[i])*(y[i] - z[i]);
    }

    int tmp = (int)sqrt((double)sum);
    if (tmp*tmp == sum)
    {
        return true;
    }
    return false;
}

int main()
{
    int N, D;
    cin >> N >> D;
    vector<vector<int>> X;

    X.resize(N);
    rep (y, N)
    {
        X[y].resize(D);
        rep (x, D)
        {
            cin >> X[y][x];
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int k = i + 1; k < N; ++k)
        {
            if (distance(X[i], X[k]))
            {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
