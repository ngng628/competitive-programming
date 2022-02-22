#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, M, X;
   cin >> N >> M >> X;
   vector<int> C(N);
   vector<vector<int>> A(N, vector<int>(M));
   for (int i = 0; i < N; i++) {
      cin >> C[i];
      for (int j = 0; j < M; j++) {
         cin >> A[i][j];
      }
   }
   int ans = 1 << 30;
   for (int i = 0; i < (1 << N); i++) {
      vector<int> S(M, 0);
      int t = 0;
      for (int j = 0; j < N; j++) {
         if (i & (1 << j)) {
            t += C[j];
            for (int k = 0; k < M; k++) {
               S[k] += A[j][k];
            }
         }
      }
      sort(S.begin(), S.end());
      if (S[0] >= X) ans = min(ans, t);
   }

   if (ans == 1 << 30) cout << -1 << endl;
   else cout << ans << endl;
}
