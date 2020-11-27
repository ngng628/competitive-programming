# include <iostream>
# include <vector>
# define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    rep (i, n) cin >> a[i];

    int ans = 0;
    rep (i, n) {
        if (X & (1 << i)) {
            ans += a[i];
        }
    }

    cout << ans << endl;

    return 0;
}
