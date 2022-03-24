# include <bits/stdc++.h>
using namespace std;

int main() {
   int n, m;
   cin >> n >> m;
   vector<vector<int>> graph(n);
   for (int _i = 0; _i < m; ++_i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   queue<pair<int, int>> que;
   vector dp(1 << n, vector<int>(n, numeric_limits<int>::max()));
   for (int v = 0; v < n; ++v) {
      que.emplace(1 << v, v);
      dp[1 << v][v] = 1;
      dp[0][v] = 0;
   }

   while (not que.empty()) {
      auto [S, last] = que.front();
      que.pop();
      for (int last2 : graph[last]) {
         int S2 = S ^ (1 << last2);
         if (dp[S2][last2] != numeric_limits<int>::max()) continue;
         dp[S2][last2] = dp[S][last] + 1;
         que.emplace(S2, last2);
      }
   }

   int ans = accumulate(dp.begin(), dp.end(), 0, [](int acc, auto& d){ return acc + *min_element(d.begin(), d.end()); });
   cout << ans << endl;
}