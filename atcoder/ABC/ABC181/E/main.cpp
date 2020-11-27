# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
using namespace std;
using ll = long long;

int main() {
   int n, m; cin >> n >> m;
   vector<int> h(n), w(m);
   rep (i, n) cin >> h[i];
   rep (i, m) cin >> w[i];
   sort(all(h));
   sort(all(w));

   // 添字 h[i-1] ( i は奇数) と w がペアを組むとして
   // left : それより左にいるベアの身長の差
   // right: それより右にいるベアの身長の差
   vector<ll> left(n+1), right(n+1);
   left[1] = 0;
   right[1] = 0;

   for (int i = 1; i+1 < n; i += 2) {
      right[1] += abs(h[i] - h[i+1]);
   }

   for (int i = 3; i < n+1; i += 2) {
      left[i] = left[i-2] + abs(h[i-3] - h[i-2]);
      right[i] = right[i-2] - abs(h[i-2] - h[i-1]);
   }

   // both : left と right の合計
   vector<ll> both(n+1);
   rep (i, n+1) both[i] = left[i] + right[i];

   ll ans = LONG_LONG_MAX;
   rep (i, m) {
      int ui = distance(h.begin(), upper_bound(all(h), w[i]));
      if (ui % 2 == 0) {
         if (ui != 0) ans = min(ans, both[ui-1] + abs(h[ui-2] - w[i]));
         ans = min(ans, both[ui+1] + abs(h[ui] - w[i]));
      }
      else {
         ans = min(ans, both[ui] + abs(h[ui-1] - w[i]));
      }
   }

   cout << ans << endl;

   return 0;
}

