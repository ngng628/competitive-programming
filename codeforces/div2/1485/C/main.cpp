# include <bits/stdc++.h>
# define int long long
using namespace std;
struct Setup_io { Setup_io(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;

struct Solver {
   void solve() {
      int x, y;
      cin >> x >> y;
      int ans = 0;
      for (int k = 1; k*k <= x; ++k) {
         ans += max(0LL, min(y, x / k - 1)  - k);
      }
      cout << ans << "\n";
   }
};

int32_t main() {
   int t;
   cin >> t;
   while (t--) {
      Solver solver;
      solver.solve();
   }
}
