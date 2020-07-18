# include <bits/stdc++.h>
# include <string>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template <class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;

int main()
{
    int N; std::cin >> N;
    string S; cin >> S;

    int x = 0;
    int max = 0;
    for (const auto& s : S)
    {
        debug(s);
        if (s == 'I')
        {
            ++x;
        }
        else 
        {
            --x;
        }

        debug(chmax(max, x));
    }

    cout << max << endl;

    return 0;
}
