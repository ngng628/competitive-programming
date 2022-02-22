# include <bits/stdc++.h>
# include <atcoder/modint>
using namespace std;

int main() {
   string K;
   int D;
   cin >> K >> D;
   const int n = K.length();

   enum Ordering { Less, Equal };
   vector dp(n + 1, vector(D, vector<atcoder::modint1000000007>(2, 0)));
   dp[0][0][Equal] = 1;
   for (int i = 0; i < n; ++i) {
      int Ki = K[i] - '0';
      for (int mod = 0; mod < D; ++mod) {
         for (int ord : { Less, Equal }) {
            for (int d = 0; d <= 9; ++d) {
               int mod2 = (mod + d) % D;
               int ord2 = ord;

               if (ord == Equal and d > Ki) continue;
               if (d < Ki) ord2 = Less;

               dp[i + 1][mod2][ord2] += dp[i][mod][ord];
            }
         }
      }
   }

   cout << (dp[n][0][Less] + dp[n][0][Equal] - 1).val() << endl;
}
