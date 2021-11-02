# include <bits/stdc++.h>
# define rep(i,n) for (int i = 0; i < (n); i++)
# define sz(v) ((int)(v).size())
using ll = long long;
using namespace std;

void Main(int n, vector<string>& w) {
    int tanku[] = {5,7,5,7,7};
    rep (i, n) {
        int cnt = 0;
        int cur = 0;
        for (int k = i; k < n; ++k) {
            cnt += sz(w[k]);
            if (cnt > tanku[cur]) break;
            else if (cnt == tanku[cur]) {
                cur++;
                cnt = 0;
            }

            if (cur == 5) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<string> w(n);
        rep (i, n) cin >> w[i];
        Main(n, w);
    }
    return 0;
}

