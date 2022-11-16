# include <iostream>
# include <vector>
# include <array>
using namespace std;

int main() {
   int ts;
   cin >> ts;
   for (int t = 0; t < ts; t++) {
      int n;
      cin >> n;
      string s;
      cin >> s;

      array<vector<int>, 10> cnt;
      for (int d = 0; d <= 9; d++) {
         cnt[d].assign(n + 1, 0);
         for (int i = 0; i < n; i++) {
            cnt[d][i + 1] = cnt[d][i] + int(s[i] == '0' + d);
         }
      }

      int ans = 0;
      for (int l = 0; l < n; l++) {
         for (int r = l + 1; r <= min(l + 1 + 123, n); r++) {
            int k = 0;
            for (int d = 0; d <= 9; d++) {
               if (cnt[d][r] - cnt[d][l] > 0) {
                  k++;
               }
            }

            bool ok = [&]() {
               for (int d = 0; d <= 9; d++) {
                  if (cnt[d][r] - cnt[d][l] > k) {
                     return false;
                  }
               }
               return true;
            }();

            if (ok) ans++;
         }
      }

      cout << ans << '\n';
   }
}