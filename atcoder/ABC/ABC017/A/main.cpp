# include <bits/stdc++.h>
# define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main() {
    int ans = 0;
    rep (i, 3) {
        int a, b;
        cin >> a >> b;
        ans += a*b/10;
    }
    cout << ans << endl;
    return 0;
}
