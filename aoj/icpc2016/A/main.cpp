# include <bits/stdc++.h>
# define rep(i,n) for (int i=0; i<(n); i++)
# define ALL(v) (v).begin(), (v).end()
using namespace std;
using VI = vector<int>;
using VVI = vector<vector<int>>;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        VI a(n);
        rep (i, n) cin >> a[i];
        sort(ALL(a));
        int ans = INT_MAX;
        rep (i, n-1) {
            ans = min(ans, a[i+1] - a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}