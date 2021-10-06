# include <bits/stdc++.h>
# include <atcoder/dsu>
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

using UnionFind = atcoder::dsu;

pii minmax(int a, int b) {
   return make_pair(min(a, b), max(a, b));
}

struct UndirectedEdge {
   UndirectedEdge() = default;
   UndirectedEdge(int _u, int _v, int w) : u(_u), v(_v), weight(w) {}
   int u, v;
   int weight;
};
bool operator <(const UndirectedEdge& iValue, const UndirectedEdge& other) { return iValue.weight < other.weight; }

struct Kruskal {
   UnionFind uf;
   int sum;
   int V;
   vec<UndirectedEdge> edges;
   set<pii> used;
   Kruskal(int _V, const vec<UndirectedEdge>& _edges) : V(_V), edges(_edges) { init(); }
   void init() {
      sort(all(edges));
      uf = UnionFind(V);
      sum = 0;

      // 負の辺は先につなげておく
      for (auto [from, to, weight] : edges) {
         if (weight <= 0 and not used.count(minmax(from, to))) {
            uf.merge(from, to);
            used.insert(minmax(from, to));
         }
      }

      for (auto [from, to, weight] : edges) {
         if (not uf.same(from, to) and weight > 0 and not used.count(minmax(from, to))) {
            uf.merge(from, to);
            used.insert(minmax(from, to));
         }
      }
   }
};

int32_t main() {
   // ────────────────────────────────────
   //  1. 入力
   // ────────────────────────────────────
   int n, m;
   cin >> n >> m;
   vec<UndirectedEdge> _edges(m);
   rep (i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      _edges[i] = UndirectedEdge(a, b, c);
   }
   sort(all(_edges));
   list<UndirectedEdge> edges(all(_edges));

   // ────────────────────────────────────
   //  2. クラスカル法っぽいことをする
   // ────────────────────────────────────
   // 非正整数の辺は必ず使う
   UnionFind ut(n);
   for (auto it = edges.begin(); it != edges.end();) {
      auto [u, v, w] = *it;
      if (w <= 0) {
         ut.merge(u, v);
         it = edges.erase(it);
      }
      else ++it;
   }
   // それでもつながっていない辺を仕方なくつなげる
   for (auto it = edges.begin(); it != edges.end();) {
      auto [u, v, w] = *it;
      if (not ut.same(u, v)) {
         ut.merge(u, v);
         it = edges.erase(it);
      }
      else ++it;
   }

   int ans = accumulate(all(edges), 0LL, [](int acc, const UndirectedEdge& e) {
      return acc + e.weight;
   });
   cout << ans << '\n';
}