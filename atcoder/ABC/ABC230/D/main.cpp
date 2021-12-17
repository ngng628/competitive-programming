# include <bits/stdc++.h>
using namespace std;

int main() {
   int N, D;
   cin >> N >> D;
   vector<pair<int, int>> lr(N);
   for (auto& [l, r] : lr) cin >> l >> r;
   sort(lr.begin(), lr.end(), [](auto& a, auto& b){ return a.second < b.second; });

   int ans = 0;
   int x = numeric_limits<int>::min();
   for (auto [l, r] : lr) {
      if (l > x) {
         ans += 1;
         x = r + D - 1;
      }
   }

   cout << ans << '\n';
}
