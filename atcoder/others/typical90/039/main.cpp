# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int int_fast64_t
# define float __long_double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
using namespace std;
using __long_double = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
using vs = vec<string>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(const char c){ return '0' <= c and c <= '9' ? (c - '0') : -1; }
# endif  // ngng628_library

struct LCA {
   vvi parent;  // parent[k][u]:= u の 2^k 先の親
   vi dist;     // root からの距離
   LCA(const vvi& graph, int root = 0) {
      int V = len(graph);
      int K = 1;
      while ((1 << K) < V) K++;
      parent.assign(K, vi(V, -1));
      dist.assign(V, -1);
      auto dfs = [&](auto&& self, int v, int p, int d) -> void {
         parent[0][v] = p;
         dist[v] = d;
         for (int u : graph[v]) {
            if (u != p) self(self, u, v, d + 1);
         }
      };
      dfs(dfs, root, -1, 0);
      rep (k, K - 1) {
         rep (v, V) {
            if (parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
         }
      }
   }

   int query(int u, int v) {
      if (dist[u] < dist[v]) swap(u, v);
      int K = len(parent);
      rep (k, K) {
         if ((dist[u] - dist[v]) >> k & 1) {
            u = parent[k][u];
         }
      }
      if (u == v) return u;
      rrep (k, K) {
         if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
         }
      }
      return parent[0][u];
   }

   int get_dist(int u, int v) { 
      return dist[u] + dist[v] - 2*dist[query(u, v)];
   }

   bool is_on_path(int u, int v, int a) {
      return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
   }
};

int32_t main() {
   int V;
   cin >> V;
   const int E = V - 1;
   vi A(V), B(V);
   vvi G(V);
   rep (i, E) {
      cin >> A[i] >> B[i];
      A[i]--, B[i]--;
      G[A[i]].pb(B[i]);
      G[B[i]].pb(A[i]);
   }

   vi dp(V);
   db closed(V, false);
   auto dfs = [&](auto&& self, int v) -> int {
      if (closed[v]) return 0;
      closed[v] = true;
      dp[v] = 1;
      for (int nxt : G[v]) {
         dp[v] += self(self, nxt);
      }
      return dp[v];
   };
   dfs(dfs, 0);

   int ans = 0;
   LCA lca(G);
   rep (i, E) {
      int a = lca.get_dist(A[i], 0);
      int b = lca.get_dist(B[i], 0);
      if (a > b) ans += dp[A[i]]*(V - dp[A[i]]);
      else ans += dp[B[i]]*(V - dp[B[i]]);
   }

   print(ans);
}