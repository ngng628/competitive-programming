//    _        _     _         _               _    
//   | |__    (_)   | |__     (_)     ___     (_)   
//   | / /    | |   | '_ \    | |    (_-<     | |   
//   |_\_\   _|_|_  |_.__/   _|_|_   /__/_   _|_|_  
// _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
// "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
//
# include <bits/stdc++.h>
# define rep(i,n) for(int i=0;i<(n);++i)
# define FI first
# define SE second
using namespace std;

constexpr array<pair<int, int>, 8> dydx8 = {{
   {1, 0}, {0, 1}, {-1, 0}, {0, -1},
   {1, 1}, {-1, -1}, {-1, 1}, {1, -1},
}};

bool over(int y, int x, int h, int w) {
   return y < 0 or y >= h or x < 0 or x >= w;
}

void Main(int w, int h, vector<vector<int>>& c) {
   vector<vector<bool>> visited(h, vector<bool>(w, false));
   int ans = 0;
   rep (y, h) rep (x, w) {
      if (visited[y][x]) continue;
      if (c[y][x] == 0) continue;

      stack<pair<int, int>> stk;
      stk.emplace(y, x);
      visited[y][x] = true;
      while (not stk.empty()) {
         pair<int, int> now = stk.top(); stk.pop();
         for (auto [dy, dx] : dydx8) {
            pair<int, int> nxt = { now.FI + dy, now.SE + dx };

            if (over(nxt.FI, nxt.SE, h, w)) continue;
            if (visited[nxt.FI][nxt.SE]) continue;
            if (c[nxt.FI][nxt.SE] == 0) continue;

            visited[nxt.FI][nxt.SE] = true;
            stk.push(nxt);
         }
      }
      ans++;
   }

   cout << ans << endl;
}

int32_t main() {
   while (true) {
      int w, h;
      cin >> w >> h;
      if (!(w | h)) break;
      vector<vector<int>> c(h, vector<int>(w));
      rep (y, h) rep (x, w) cin >> c[y][x];
      Main(w, h, c);
   }

   return 0;
}
