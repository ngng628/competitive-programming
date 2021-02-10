# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define len(v) (int)(std::size(v))
# define eb emplace_back
# define int long long
using namespace std;
template<class T> using vec = vector<T>;
template<class T> inline constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
constexpr int INF = (1LL<<62)-(1LL<<31);

// ──────────────────────
//  重み付きグラフ構造体
// ──────────────────────
struct Edge {
   Edge() = default;
   Edge(int t, int w = 0) : to(t), weight(w) {}
   int to;
   int weight;
};
using Graph = vector<vector<Edge>>;

// ──────────────────────
//  入力
// ──────────────────────
auto read() {
   int n, m;
   cin >> n >> m;
   vvi G(n, vi(n, INF));
   vi self(n, INF);
   rep (i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      G[a][b] = min(G[a][b], c);
      if (a == b) self[a] = min(self[a], c);
   }

   Graph graph(n);
   rep (i, n) rep (j, n) if (G[i][j] != INF) graph[i].eb(j, G[i][j]);
   return make_tuple(n, m, graph, self);
}

// ──────────────────────
//  ダイクストラ法
// ──────────────────────
vvi dijkstra(const Graph& graph) {
   const int V = len(graph);
   vvi ret(V, vi(V, INF));
   rep (start, V) {
      vi& dist = ret[start];
      priority_queue<pii, vec<pii>, greater<pii>> pq; // {dist, to}
      dist[start] = 0;
      pq.emplace(dist[start], start);
      while (not pq.empty()) {
         auto [d, now] = pq.top(); pq.pop();
         if (dist[now] < d) continue;
         for (auto& edge : graph[now]) {
            if (chmin(dist[edge.to], dist[now] + edge.weight)) {
               pq.emplace(dist[now] + edge.weight, edge.to);
            }
         }
      }
   }
   return ret;
}

int32_t main() {
   auto [n, m, graph, self] = read();

   vvi dist = dijkstra(graph);
   rep (i, n) {
      int ans = self[i];
      rep (j, n) {
         if (i == j) continue;
         ans = min(ans, dist[i][j] + dist[j][i]);
      }
      cout << (ans == INF ? -1 : ans) << endl;
   }
}
