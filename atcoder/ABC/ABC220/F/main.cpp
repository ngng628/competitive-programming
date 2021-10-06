# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (int)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr int INF = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void drop(){ cout << '\n'; exit(0); }
template<class T, class... A> void drop(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << ' '; drop(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

template<class DP, DP (*connect)(const DP&)>
struct Rerooting {
   Rerooting(int n) : graph(n), _n(n) {
      dp.resize(n);
      ans.resize(n, DP::e());
   }

   Rerooting(vvi g, bool should_build = true) : graph(g), _n(len(g)) {
      if (should_build) build();
   }

   Rerooting(int n, vec<pii> edges, bool should_build = true) : Rerooting(n) {
      for (auto [s, t] : edges) add_edge(s, t);
      if (should_build) build();
   }

   void add_edge(int s, int t) {
      assert(0 <= s and s < _n);
      assert(0 <= t and t < _n);
      graph[s].pb(t);
   }

   void build() { dfs(0); bfs(0, DP::e()); }

   DP get(int i) const {
      assert(0 <= i and i < _n);
      return ans[i];
   }

private:
   vec<vec<DP>> dp;
   vec<DP> ans;
   vvi graph;
   int _n;

   DP dfs(int v, int p = -1) {
      DP dp_cum = DP::e();
      int deg = len(graph[v]);
      dp[v] = vec<DP>(deg, DP::e());
      rep (i, len(graph[v])) {
         int u = graph[v][i];
         if (u == p) continue;
         dp[v][i] = dfs(u, v);
         dp_cum = dp_cum * dp[v][i];
      }
      return connect(dp_cum);
   }

   void bfs(int v, const DP& dp_p, int p = -1) {
      int deg = len(graph[v]);
      rep (i, deg) {
         if (graph[v][i] == p) dp[v][i] = dp_p;
      }
      vec<DP> dp_l(deg + 1, DP::e()), dp_r(deg + 1, DP::e());
      rep (i, deg) dp_l[i + 1] = dp_l[i] * dp[v][i];
      rrep (i, deg) dp_r[i] = dp_r[i + 1] * dp[v][i];

      ans[v] = connect(dp_l[deg]);

      rep (i, deg) {
         int u = graph[v][i];
         if (u == p) continue;
         bfs(u, connect(dp_l[i] * dp_r[i + 1]), v);
      }
   }
};

struct Monoid {
   int val;
   int child;
   static Monoid e() { return Monoid{0, 0}; }
   friend ostream& operator <<(ostream& os, const Monoid& x){ return os << x.val; }
};
Monoid operator *(const Monoid& a, const Monoid& b) { return Monoid{a.val + b.val, a.child + b.child}; }
Monoid connect(const Monoid& c){ return Monoid{c.val + c.child, c.child + 1}; }

int32_t main() {
   int n;
   cin >> n;
   Rerooting<Monoid, connect> reroot(n);
   rep (i, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      reroot.add_edge(u, v);
      reroot.add_edge(v, u);
   }
   reroot.build();

   rep (i, n) {
      cout << reroot.get(i) << '\n';
   }
}