# include <bits/stdc++.h>
# include <atcoder/dsu>
using namespace std;

int main() {
   int n, m;
   cin >> n >> m;
   vector<int> a(m);
   for (int& e : a) {
      cin >> e;
   }

   atcoder::dsu ut(n);
   for (int i = 0; i < m; i++) {
      ut.merge(a[i] - 1, a[i]);
   }

   auto groups = ut.groups();
   sort(groups.begin(), groups.end(), [](const auto& lhs, const auto& rhs) {
      return lhs[0] < rhs[0];
   });

   vector<int> ans;
   ans.reserve(n);
   for (auto& group : groups) {
      sort(group.begin(), group.end());
      reverse(group.begin(), group.end());
      for (int member : group) {
         ans.push_back(member + 1);
      }
   }

   for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
   }

   return 0;
}