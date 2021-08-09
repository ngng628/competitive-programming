# include <bits/stdc++.h>
# define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
# define eb emplace_back
# define ef emplace_front
# define mkp make_pair
using namespace std;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
template<class T> constexpr bool chmin(T &a, const T& b){ return a > b && (a = b, true); }
constexpr int INF = (1<<30)-(1<<15);

struct Edge {
   Edge() = default;
   Edge(pii t, int w = 0) : to(t), weight(w) {}
   pii to;
   int weight;
};
using Graph = vec<vec<Edge>>;

int32_t main() {
   int h, w;
   cin >> h >> w;
   vec<string> s(h);
   for (auto& e : s) cin >> e;
   auto over = [&h, w](int y, int x) { return y < 0 or y >= h or x < 0 or x >= w; };

   vec<vec<int>> dist(h, vec<int>(w, INF));
   dist[0][0] = 0;
   for (deque<pii> dq({{0, 0}}); not dq.empty();) {
      pii now = dq.front(); dq.pop_front();
      vec<Edge> edges;
      FORE (dy, -2, 2) {
         FORE (dx, -2, 2) {
            if (abs(dy) + abs(dx) == 4) continue;
            if (!(dy | dx)) continue;
            int ny = now.first + dy;
            int nx = now.second + dx;
            if (over(ny, nx)) continue;
            if (abs(dy) + abs(dx) == 1 and s[ny][nx] == '.') edges.eb(mkp(ny, nx), 0);
            else edges.eb(mkp(ny, nx), 1);
         }
      }
      for (auto [nxt, cost] : edges) {
         int c = dist[now.first][now.second] + cost;
         if (chmin(dist[nxt.first][nxt.second], c)) {
            if (cost) dq.eb(nxt);
            else dq.ef(nxt);
         }
      }
   }

   cout << dist.back().back() << '\n';
}