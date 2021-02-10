# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (int)(n); ++i)
# define repr(i, a, n) for (int i = (int)a; i < (int)(n); ++i)
# define rrep(i, n) for (int i = (int)n-1; i >= 0; --i)
# define del(v, x, y) (v).at(x).erase((v).at(x).begin() + y)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int solve(int h, int w, int k, vvi& b);

int32_t main() {
   int h, w, k;
   cin >> h >> w >> k;
   vector<string> c(h);
   rep (i, h) cin >> c[i];

   vvi board(w+1, vi(2*h, 0));
   rrep (y, h) rep (x, w) board[x][h-y-1] = c[y][x] - '0';

   int ans = 0;
   rep (y, h) rep (x, w) {
      vvi b = board;
      del(b, x, y);

      int score = 0;
      int ratio = 1;
      for (int sum; sum = solve(h, w, k, b);) {
         score += ratio * sum;
         ratio *= 2;
      }

      ans = max(ans, score);
   }

   cout << ans << "\n";
}

int solve(int h, int w, int k, vvi& b) {
   vector<tuple<int, int, int>> dels;

   rrep (y, h) {
      stack<int> stk;
      rep (x, w + 1) {
         int now = b[x][y];
         if (now != 0 and stk.empty()) stk.push(now);
         else if (not stk.empty() and stk.top() == now) stk.push(now);
         else {
            if (stk.size() >= k) {
               repr (i, x - stk.size(), x) dels.emplace_back(i, y, stk.top());
            }
            stk = stack<int>();
            if (now != 0) stk.push(now);
         }
      }
   }

   int score = 0;
   for (auto [x, y, number] : dels) {
      del(b, x, y);
      score += number;
   }
   return score;
}