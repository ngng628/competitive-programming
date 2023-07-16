# include <bits/stdc++.h>
# define rep(i, a, b) for (ll i = a; i < ll(b); i++)
# define all(v) std::begin(v), std::end(v)
# define len(v) ll(std::size(v))
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

int main() {
   int h, w;
   cin >> h >> w;
   vector<string> s(h);
   rep (i, 0, h) cin >> s[i];
   auto over = [h, w](int y, int x) { return y < 0 or y >= h or x < 0 or x >= w; };

   if (s[0][0] != 's') {
      cout << "No" << endl;
      return 0;
   }

   int delta[] = {0, -1, 0, 1, 0};
   map<char, int> f = {
      {'s', 0},
      {'n', 1},
      {'u', 2},
      {'k', 3},
      {'e', 4},
   };

   string snuke = "snuke";
   vector visited(h, vector(w, vector(len(snuke), 0)));
   queue<tuple<int, int, int>> que;
   que.emplace(0, 0, 0);
   visited[0][0][0] = true;
   while (not que.empty()) {
      auto [y, x, state] = que.front();
      que.pop();
      rep (i, 0, 4) {
         int ny = y + delta[i];
         int nx = x + delta[i + 1];
         int ns = (state + 1) % len(snuke);
         if (over(ny, nx)) continue;
         if (visited[ny][nx][ns]) continue;
         if (f[s[ny][nx]] != ns) continue;
         visited[ny][nx][ns] = true;
         que.emplace(ny, nx, ns);
      }
   }

   bool ok = any_of(all(visited[h - 1][w - 1]), [](bool b){ return b; });
   cout << (ok ? "Yes" : "No") << endl;
}