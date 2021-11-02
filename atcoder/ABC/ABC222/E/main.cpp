# include <bits/stdc++.h>
# include <atcoder/modint>
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
constexpr int oo = (1LL<<62)-(1LL<<31);
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

using Fp = atcoder::modint998244353;
istream& operator >>(istream& is, Fp& r){ int t; is >> t; r = t; return is; }
ostream& operator <<(ostream& os, const Fp& r){ return os << r.val(); }

struct Edge {
   Edge() = default;
   Edge(int t, int w = 0) : to(t), weight(w) {}
   int to;
   int weight;
};
using Graph = vec<vec<Edge>>;

vec<Fp> subset_sum(const vi& a, int K) {
   vec<Fp> dp(K+1, false);
   dp[0] = 1;
   for (const auto& e : a) {
      for (int k = K; k >= e; --k) {
         dp[k] += dp[k - e];
      }
   }
   return dp;
}

int32_t main() {
   // ────────────────────────────────
   //  1. 入力
   // ────────────────────────────────
   int n, m, k;
   cin >> n >> m >> k;
   vi a(m);
   rep (i, m) cin >> a[i], a[i]--;
   Graph graph(n);
   rep (i, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      graph[u].eb(v, 0);
      graph[v].eb(u, 0);
   }

   // ────────────────────────────────
   //  2. 通る辺をカウント
   // ────────────────────────────────
   vi all_route;
   vvi edges(n, vi(n, -oo));
   rep (i, m - 1) {
      int s = a[i];
      int t = a[i + 1];
      db visited(n, false);
      visited[s] = true;
      vi prev(n, 0);
      prev[s] = -1;
      for (queue<int> que({s}); not que.empty();) {
         int now = que.front(); que.pop();
         for (auto [nxt, _] : graph[now]) {
            if (visited[nxt]) continue;
            prev[nxt] = now;
            visited[nxt] = true;
            que.push(nxt);
         }
      }

      vi route;
      for (int now = t; now != -1; now = prev[now]) {
         route.push_back(now);
      }
      reverse(all(route));
      all_route.insert(all_route.end(), route.begin(), route.end() - 1);
      rep (j, len(route) - 1) {
         int a = route[j];
         int b = route[j + 1];
         if (edges[a][b] == -oo) {
            edges[a][b] = 0;
            edges[b][a] = 0;
         }
         edges[a][b]++;
         edges[b][a]++;
      }
   }
   all_route.pb(a.back());

   vi ws; // ws[i] 回通る辺があります
   rep (u, n) {
      repr (v, u + 1, n) {
         if (edges[u][v] > 0) ws.push_back(edges[u][v]);
      }
   }
   Fp other = Fp(2).pow((n - 1) - len(ws));

   auto ss = subset_sum(ws, 100'000 + 1);
   int sum = accumulate(all(ws), int(0));
   int rval = (sum + k) / 2;
   cout << ((sum + k) & 1 or sum + k < 0 ? 0 : ss[rval]) * other << endl;
}