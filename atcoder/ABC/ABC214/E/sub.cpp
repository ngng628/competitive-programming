# include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve() {
   int n;
   cin >> n;
   vector<pii> lr(n);
   for (auto& [l, r] : lr) cin >> l >> r;

   sort(lr.begin(), lr.end(), [](const pii& a, const pii& b) {
      return a.second < b.second;
   });


   map<int, int> mp;
   auto find = [&](auto&& self, int l) -> int {
      if (mp[l] == 0) {
         return l;
      }
      else if (mp[l] == l) {
         return l;
      }
      else {
         int par = self(self, abs(mp[l]));
         mp[l] = par;
         return par;
      }
   };

   auto unite = [&](int u, int v) -> void {
      int lu = find(find, u);
      int lv = find(find, v);
      if (lu == lv) {
         return;
      }
      mp[max(lu, lv)] = 0;
      mp[min(lu, lv)] = -max(lu, lv);
   };

   for (auto [l, r] : lr) {
      int ok = find(find, l);
      if (ok > r) {
         cout << "No\n";
         return;
      }
      unite(ok, ok + 1);
   }

   cout << "Yes\n";
}

int main() {
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}