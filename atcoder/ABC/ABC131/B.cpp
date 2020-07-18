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

int sum_of(vector<int> values)
{
    int sum = 0;
    for (int i = 0; i < SZ(values); ++i)
    {
        sum += values[i];
    }
    return sum;
}

int main()
{
    int N, L;
    cin >> N >> L;

    vector<int> taste;
    for (int i = 1; i <= N; ++i)
    {
        taste.push_back(L + i - 1);
    }

    if (taste[0] >= 0 && taste[N-1] > 0)
    {
        taste[0] = 0;
        cout << sum_of(taste) << "\n";
    }
    else if (taste[0] < 0 && taste[N-1] >= 0)
    {
        cout << sum_of(taste) << "\n";
    }
    else
    {
        taste[N-1] = 0;
        cout << sum_of(taste) << "\n";
    }

    return 0;
}
