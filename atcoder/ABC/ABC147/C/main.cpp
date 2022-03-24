# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> A(n);
   vector<vector<int>> x(n), y(n);
   for (int i = 0; i < n; ++i) {
      cin >> A[i];
      x[i].resize(A[i]);
      y[i].resize(A[i]);
      for (int j = 0; j < A[i]; ++j) {
         cin >> x[i][j] >> y[i][j];
         x[i][j]--;
      }
   }

   int ans = 0;
   for (int mask = 0; mask < (1 << n); ++mask) {
      auto ok = [&]() {
         for (int i = 0; i < n; ++i) if ((mask >> i) & 1) {
            for (int j = 0; j < A[i]; ++j) {
               if (bool((mask >> x[i][j]) & 1) ^ y[i][j]) return false;
            }
         }
         return true;
      }();
      if (ok) ans = max(ans, __builtin_popcount(mask));
   }

   cout << ans << '\n';
}