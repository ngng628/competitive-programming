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

class StronglyConnectedComponents {
public:
   vvi graph;
   vi comp;

   StronglyConnectedComponents(const vvi& _g)
      : comp(len(_g), -1), g(_g), gg(len(_g)), rg(len(_g)), used(len(_g))
   {
      rep (i, len(_g)) for (int v : g[i]) {
         gg[i].pb(v);
         rg[v].pb(i);
      }
      build();
   }

   int operator[](int k) { return comp[k]; }

   bool same(int s, int t) { 
      return comp[s] == comp[t];
   }

private:
   const vvi& g;
   vvi gg, rg;
   vi order, used;

   void dfs(int idx) {
      if (used[idx]) return;
      used[idx] = true;
      for(int to : gg[idx]) dfs(to);
      order.pb(idx);
   }

   void rdfs(int idx, int cnt) {
      if (comp[idx] != -1) return;
      comp[idx] = cnt;
      for (int to : rg[idx]) rdfs(to, cnt);
   }

   void build() {
      rep (i, len(gg)) dfs(i);
      reverse(all(order));
      int ptr = 0;
      for (int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

      if (not graph.empty()) graph.clear();
      graph.resize(ptr);
      rep (i, len(graph)) {
         for (int to : g[i]) {
            int x = comp[i], y = comp[to];
            if (x == y) continue;
            graph[x].pb(y);
         }
      }
   }
};

int32_t main() {
   int v, e;
   cin >> v >> e;
   vvi graph(v);
   rep (i, e) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      graph[a].pb(b);
   }

   StronglyConnectedComponents scc(graph);

   int ans = 0;
   auto f = [](int n){ return n * (n - 1) / 2; };
   map<int, int> mp;
   for (int c : scc.comp) mp[c]++;
   for (pii p : mp) {
      ans += f(p.se);
   }
   print(ans);
}