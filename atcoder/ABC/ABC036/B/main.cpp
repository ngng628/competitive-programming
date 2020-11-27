# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
using namespace std;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }

signed main() {
    int n;
    cin >> n;
    vector<string> s(n);
    cin >> s;

    rep (x, n) {
        rrep (y, n) {
            cout << s[y][x];
        }
        cout << endl;
    }

    return 0;
}

