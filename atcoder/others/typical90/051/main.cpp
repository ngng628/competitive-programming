# include <bits/stdc++.h>
# define rep(i,n) for(int i = 0; i < (int)(n); ++i)
# define all(v) (v).begin(), (v).end()
# define int long long
using namespace std;

int32_t main() {
   int n, k, p;
   cin >> n >> k >> p;
   vector<int> a(n);
   for (int& e : a) cin >> e;
   
   int m = n / 2;
   // k 種類選ぶと、f[k][any] 円にできますよ
   vector<vector<int>> f(max(k, m) + 1),
                       s(max(k, n - m) + 1);
   rep (bit, 1 << m) {
      int sum = 0, cnt = 0;
      rep (i, m) if ((bit >> i) & 1) {
         sum += a[i];
         cnt++;
      }
      f[cnt].push_back(sum);
   }
   rep (bit, 1 << (n - m)) {
      int sum = 0, cnt = 0;
      rep (i, n - m) if ((bit >> i) & 1) {
         sum += a[m + i];
         cnt++;
      }
      s[cnt].push_back(sum);
   }
   for (auto& v : f) sort(all(v));
   for (auto& v : s) sort(all(v));
   
   int ans = 0;
   // 前半から i 種類取る
   rep (i, k + 1) {
      // i 種類取った時の総和は f[i][j] ですよ
      rep (j, f[i].size()) {
         // 後半から k - i 種類とったとき、
         // 残りの p - f[i][j] 円になるのは何個？
         auto ub = upper_bound(all(s[k - i]), p - f[i][j]);
         ans += distance(s[k - i].begin(), ub);
      }
   }
   
   cout << ans << endl;
}