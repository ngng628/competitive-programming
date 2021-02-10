# include <bits/stdc++.h>
# include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main() {
   int n, m;
   cin >> n >> m;
   vector<int> a(m), b(m);
   for (int i = 0; i < m; i++) {
      cin >> a[i] >> b[i];
      a[i]--; b[i]--;
   }

   int ans = 0;
   for (int i = 0; i < m; i++) {
      dsu tree(n);
      for (int j = 0; j < m; j++) {
         if (i == j) continue;
         tree.merge(a[j], b[j]);
      }
      if (tree.groups().size() != 1) ans++;
   }

   cout << ans << "\n";
}
