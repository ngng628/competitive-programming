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
    string S; cin >> S;

    lint sum = 0;
    for (int bit = 0; bit < (1 << (S.length() - 1)); ++bit)
    {
        lint num = S[0] - '0';
        for (int i = 0; i < S.length() - 1; ++i)
        {
            if (bit & (1 << i))
            {
                sum += num;
                num = 0;
            }
            num = num * 10 + (S[i+1] - '0');
        }
        sum += num;
    }

    cout << sum << "\n";

    return 0;
}
