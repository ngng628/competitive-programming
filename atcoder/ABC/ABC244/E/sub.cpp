# include <bits/stdc++.h>
# include <atcoder/modint>
# pragma GCC diagnostic ignored "-Wunused-result"

int main() {
   int n, m, K, s, t, X;
   scanf("%d%d%d%d%d%d", &n, &m, &K, &s, &t, &X);
   s--, t--, X--;
   std::vector<std::pair<int, int>> edges(2*m);
   for (int i = 0; i < m; ++i) {
      scanf("%d%d", &edges[i].first, &edges[i].second);
      edges[i].first--, edges[i].second--;
      edges[i + m] = std::make_pair(edges[i].second, edges[i].first);
   }

   std::vector dp(n, std::vector(K + 1, std::vector<atcoder::modint998244353>(2, 0)));
   dp[s][0][s != X] = 1;
   for (int k = 0; k < K; ++k) {
      for (auto [from, to] : edges) {
         for (int iseven : {0, 1}) {
            dp[to][k + 1][iseven] += dp[from][k][iseven ^ (to == X)];
         }
      }
   }

   printf("%ud\n", dp[t][K][true].val());
}