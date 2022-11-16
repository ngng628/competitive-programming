# include <bits/stdc++.h>
using namespace std;

int main() {
   int ts;
   cin >> ts;
   for (int t = 0; t < ts; t++) {
      //───────────────────────────────
      // 1. 入力
      //───────────────────────────────
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
         cin >> a[i];
      }

      //───────────────────────────────
      // 2. 累積和を求める
      //───────────────────────────────
      vector<int64_t> csum(n, 0);
      for (int i = 0; i < n; i++) {
         csum[i] = csum[max(0, i - 1)] + a[i];
      }

      //───────────────────────────────
      // 3. 数列を分割する
      //───────────────────────────────
      vector<vector<int>> splited_indices(1, vector<int>());
      for (int i = 0; i < n; i++) {
         if (a[i] == 0) {
            splited_indices.push_back(vector<int>());
         }
         splited_indices.back().push_back(i);
      }

      //───────────────────────────────
      // 4. 問題を解く
      //───────────────────────────────
      int ans = 0;
      for (int epoch = 0; const vector<int>& indices : splited_indices) {
         // 最初の数列は流れに身を任せるしかない
         if (epoch == 0) {
            for (int i : indices) {
               if (csum[i] == 0) {
                  ans++;
               }
            }
         }
         // それ以降の数列
         else {
            unordered_map<int64_t, int> mp;
            for (int i : indices) {
               mp[csum[i]]++;
            }

            int64_t mode = 0;
            for (auto [_, cnt] : mp) {
               if (mode < cnt) {
                  mode = cnt;
               }
            }

            ans += mode;
         }
         epoch++;
      }

      cout << ans << '\n';
   }
}