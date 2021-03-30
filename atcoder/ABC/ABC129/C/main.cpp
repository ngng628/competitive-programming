# include <bits/stdc++.h>
# include <atcoder/modint>
using namespace std;

int main() {
   size_t n, m;
   cin >> n >> m;
   vector<bool> broken(n+1, false);
   while (m--) {
      uint32_t x;
      cin >> x;
      broken[x] = true;
   }

   vector<atcoder::modint1000000007> dp(n+1);
   dp[0] = broken[0] ? 0 : 1;
   dp[1] = broken[1] ? 0 : dp[0];
   for (size_t i = 2; i <= n; ++i) {
      if (broken[i]) dp[i] = 0;
      else dp[i] = dp[i-1] + dp[i-2];
   }

   cout << dp[n].val() << "\n";
}
