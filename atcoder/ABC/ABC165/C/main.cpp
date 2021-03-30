# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
   int N, M, Q;
   cin >> N >> M >> Q;
   vector<array<int, 4>> query(Q);
   rep (i, Q) rep (j, 4) cin >> query[i][j];

   int ans = 0;
   auto dfs = [&](auto&& self, vector<int> A, int x) -> void {
      A.push_back(x);
      if ((int)A.size() == N) {
         int score = 0;
         for (auto [a, b, c, d] : query) {
            if (A[b-1] - A[a-1] == c) score += d;
         }
         ans = max(ans, score);
      }
      else {
         for (int i = A.back(); i < M; ++i) {
            self(self, A, i);
         }
      }
   };

   rep (i, M) {
      vector<int> phi = {};
      dfs(dfs, phi, i);
   }

   cout << ans << endl;
}