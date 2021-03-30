# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (int)(n); ++i)
# define reps(i, n) for (int i = 1; i <= (int)(n); ++i)
using namespace std;
using ll = long long;
constexpr int INF = (1LL<<30)-(1LL<<15);
constexpr ll LINF = (1LL<<62)-(1LL<<31);

auto read() {
   int n;
   cin >> n;
   vector<int> x(n), c(n);
   rep (i, n) cin >> x[i] >> c[i];

   set<int> st;
   rep (i, n) st.insert(c[i]);
   map<int, int> mp;
   int idx = 0;
   for (int e : st) mp[e] = idx++;

   deque<int> left(st.size(), INF), right(st.size(), -INF);
   rep (i, n) {
      left[mp[c[i]]] = min(left[mp[c[i]]], x[i]);
      right[mp[c[i]]] = max(right[mp[c[i]]], x[i]);
   }

   left.push_front(0);
   left.push_back(0);
   right.push_front(0);
   right.push_back(0);

   return tuple{left.size() - 1, left, right};
}

int main() {
   auto [n, left, right] = read();

   vector dp(n+1, vector<ll>(2, LINF));
   dp[0][0] = 0;
   dp[0][1] = 0;
   reps (i, n) {
      dp[i][0] = min(dp[i][0], dp[i-1][0] + abs(right[i-1] - left[i]) + abs(left[i] - right[i]));
      dp[i][0] = min(dp[i][0], dp[i-1][1] + abs(left[i-1] - left[i]) + abs(left[i] - right[i]));

      dp[i][1] = min(dp[i][1], dp[i-1][0] + abs(right[i-1] - right[i]) + abs(right[i] - left[i]));
      dp[i][1] = min(dp[i][1], dp[i-1][1] + abs(left[i-1] - right[i]) + abs(right[i] - left[i]));
   }

   cout << dp[n][0] << "\n";
}
