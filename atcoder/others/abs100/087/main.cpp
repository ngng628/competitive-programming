# include <bits/stdc++.h>
# include <atcoder/dsu>
using namespace std;
using UnionFind = atcoder::dsu;

int main() {
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   int n, m;
   cin >> n >> m;
   vector<int> a(m), b(m);
   for (int i = 0; i < m; i++) {
      cin >> a[i] >> b[i];
      a[i]--;
      b[i]--;
   }

   vector<int64_t> ans(m);
   UnionFind ut(n);
   ans.back() = int64_t(n) * (n - 1) / 2;
   for (int i = m - 2; i >= 0; i--) {
      if (ut.same(a[i + 1], b[i + 1])) {
         ans[i] = ans[i + 1];
      }
      else {
         int64_t g1 = ut.size(a[i + 1]);
         int64_t g2 = ut.size(b[i + 1]);
         ans[i] = ans[i + 1] - g1 * g2;
      }
      ut.merge(a[i + 1], b[i + 1]);
   }

   for (int i = 0; i < m; i++) {
      cout << ans[i] << endl;
   }
}