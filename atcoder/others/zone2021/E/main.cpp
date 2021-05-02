# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(int)(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
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

struct Edge {
   Edge() = default;
   Edge(int t, int w = 0) : to(t), weight(w) {}
   int to;
   int weight;
};
using Graph = vec<vec<Edge>>;

int32_t main() {
   int R, C;
   cin >> R >> C;
   vvi A(R, vi(C - 1)), B(R-1, vi(C));
   cin >> A >> B;

   vi dist(2*R*C, INF);
   priority_queue<pii, vec<pii>, greater<pii>> pq; // {dist, to}
   dist[0] = 0;
   pq.emplace(dist[0], 0);
   while (not pq.empty()) {
      auto [d, now] = pq.top(); pq.pop();
      if (dist[now] < d) continue;

      vec<Edge> edges;
      auto node = [&C](int y, int x) { return C*y + x; };

      if (now < R*C) {  // 地上モード
         auto [y, x] = div(now, C);
         if (x + 1 < C) edges.eb(node(y, x+1), A[y][x]);
         if (x - 1 >= 0) edges.eb(node(y, x-1), A[y][x-1]);
         if (y + 1 < R) edges.eb(node(y+1, x), B[y][x]);
         edges.eb(now + R*C, 1);
      }
      else {  // 地下鉄モード
         auto [y, x] = div(now - R*C, C);
         if (y - 1 >= 0) edges.eb(node(y - 1, x) + R*C, 1);
         edges.eb(now - R*C, 0);
      }

      for (auto& edge : edges) {
         if (chmin(dist[edge.to], dist[now] + edge.weight)) {
            pq.emplace(dist[now] + edge.weight, edge.to);
         }
      }
   }

   print(dist[R*C - 1]);
}