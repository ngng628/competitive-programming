# include <bits/stdc++.h>
# include <atcoder/dsu>
using namespace std;

int main() {
   int n, t, m;
   cin >> n >> t >> m;
   vector<pair<int, int>> ab(m);
   for (auto& [a, b] : ab) {
      cin >> a >> b;
      a--, b--;
   }

   long ans = 0;
   auto rec = [&](auto&& rec, vector<vector<int>>& ary, int i) -> void {
      if (i == n) {
         for (int j = 0; j < t; j++) {
            if (ary[j].empty()) return;
         }

         atcoder::dsu ut(n);
         for (int j = 0; j < t; j++) {
            for (int k = 0; k < (int)ary[j].size() - 1; k++) {
               ut.merge(ary[j][k], ary[j][k + 1]);
            }
         }
         for (auto [a, b] : ab) {
            if (ut.same(a, b)) return;
         }

         ans++;
         return;
      }
      
      for (int j = 0; j < t; j++) {
         bool flg = ary[j].empty();
         ary[j].push_back(i);
         rec(rec, ary, i + 1);
         ary[j].pop_back();
         if (flg) break;
      }
   };

   vector<vector<int>> phi(t);
   rec(rec, phi, 0);

   cout << ans << endl;
}