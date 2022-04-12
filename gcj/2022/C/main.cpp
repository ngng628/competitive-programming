# include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   multiset<int> s;
   for (int _i = 1; _i <= n; ++_i) {
      int x;
      cin >> x;
      s.insert(x);
   }

   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      auto it = s.lower_bound(i);
      if (it == s.end()) break;
      ans += 1;
      s.erase(it);
   }

   cout << ans << endl;
}

int main() {
   int t;
   cin >> t;
   for (int i = 1; i <= t; ++i) {
      printf("Case #%d: ", i);
      solve();
   }
}