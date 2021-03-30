# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
using namespace std;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
using vs = vec<string>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if(sizeof...(args))cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
# endif  // ngng628_library

constexpr array<pair<int, int>, 4> dydx4 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

struct Edge {
   Edge() = default;
   Edge(int t, int w = 0) : to(t), weight(w) {}
   int to;
   int weight;
};
using Graph = vec<vec<Edge>>;

int start, goal;
int dijkstra(const Graph& graph, int cost) {
   vec<int> dist(len(graph), INF);
   priority_queue<pii, vec<pii>, greater<pii>> pq; // {dist, to}
   dist[start] = 0;
   pq.emplace(dist[start], start);
   while (not pq.empty()) {
      auto [d, now] = pq.top(); pq.pop();
      if (dist[now] < d) continue;
      for (auto& edge : graph[now]) {
         int w = edge.weight == INF ? cost : 1;
         if (chmin(dist[edge.to], dist[now] + w)) {
            pq.emplace(dist[now] + w, edge.to);
         }
      }
   }
   return dist[goal];
}

int32_t main() {
   int H, W, T;
   cin >> H >> W >> T;
   vs s(H);
   cin >> s;
   int V = H*W;
   auto node = [&W](int y, int x) { return W*y + x; };

   rep (y, H) rep (x, W) {
      if (s[y][x] == 'S') start = node(y, x);
      if (s[y][x] == 'G') goal = node(y, x);
   }

   Graph graph(V);
   rep (y, H) rep (x, W) {
      if (y + 1 < H)  graph[node(y, x)].eb(node(y + 1, x), s[y+1][x] == '#' ? INF : 1);
      if (x + 1 < W)  graph[node(y, x)].eb(node(y, x + 1), s[y][x+1] == '#' ? INF : 1);
      if (y - 1 >= 0) graph[node(y, x)].eb(node(y - 1, x), s[y-1][x] == '#' ? INF : 1);
      if (x - 1 >= 0) graph[node(y, x)].eb(node(y, x - 1), s[y][x-1] == '#' ? INF : 1);
   }

   int ok = 0;
   int ng = INF;
   while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (dijkstra(graph, mid) <= T) ok = mid;
      else ng = mid;
   }

   print(ok);
}
