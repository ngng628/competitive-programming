# include <bits/stdc++.h>
# define rep(i,n) for(int i=0; i<(n); ++i)
# define sz(v) (int)(v).size()
# define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    rep (i, n) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        reverse(s.begin() + l, s.begin() + r + 1);
    }
    cout << s << endl;
    return 0;
}
