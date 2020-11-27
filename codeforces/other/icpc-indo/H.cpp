# include <bits/stdc++.h>
# define rep(i,n) for (int i = 0; i < (n); i++)
# define all(v) (v).begin(), (v).end()
# define sz(v) ((int)(v).size())
using namespace std;
using ll = long long;

void Main(int a, int b, int c, int d) {
    string s;
    int ad = a + d;
    int bc = b + c;
    if (ad != 0 and bc != 0) {
        s = "xxoo";
    } else if (bc == 0) {
        s = "xxxo";
    } else if (ad == 0) {
        s = "xxox";
    }

    if ((a+b) & 1) {
        reverse(all(s));
    }

    rep (i, sz(s)) {
        if (s[i] == 'o') {
            cout << "Ya";
        } else {
            cout << "Tidak";
        }
        if (i < sz(s) - 1) cout << " ";
        else cout << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        Main(a, b,c,d);
    }
    return 0;
}