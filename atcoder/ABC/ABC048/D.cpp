# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((lint)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    string s; cin >> s;
    if (!(SZ(s) & 0x1))
    {
        cout << "Second" << "\n";
    }
    else
    {
        lint med = SZ(s) / 2;
        s.erase(s.begin() + med);
        char left  = s[med - 1];
        char right = s[med];
        if (left == right)
        {
            cout << "Second" << "\n";
        }
        else
        {
            cout << "First" << "\n";
        }
    }

    return 0;
}
