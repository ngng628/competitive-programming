# include <bits/stdc++.h>
# define rep(i,n) for(int i = 0; i < (int)(n); i++)
# define reps(i,n) for(int i = 1; i <= (int)(n); i++)
# define all(v) (v).begin(), (v).end()
# define rall(v) (v).rbegin(), (v).rend()
# define sz(v) ((int) (v).size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    while (1) {
        int x, y, s;
        cin >> x >> y >> s;
        if (!(x | y | s)) break;
        int ans = -1;
        reps (i, 1e3 + 10) {
            reps (k, 1e3 + 10) {
                int a = (double)(100.0 + x) * i / 100.0;
                int b = (double)(100.0 + x) * k / 100.0;
                if (a + b == s) {
                    int na = (double)(100.0 + y) * i / 100.0;
                    int nb = (double)(100.0 + y) * k / 100.0;
                    ans = max(ans, na + nb);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}