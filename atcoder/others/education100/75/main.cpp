# include <bits/stdc++.h>
# include <atcoder/modint>
# ifndef ngng628_library
# define ngng628_library
# define fi first
# define se second
# define rep(i,n) for(usize i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(usize i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(usize i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(usize i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(usize i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(usize i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define contains(x,key) ((x).find(key) != (x).end())
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
using namespace atcoder;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
using f32 = float;
using f64 = long double;
using usize = size_t;
template<class T> using vec = vector<T>;
using pii = pair<i64, i64>;
using vi = vec<i64>;
using vb = vec<bool>;
using vvb = vec<vb>;
using vvvb = vec<vvb>;
using vs = vec<string>;
using vpii = vec<pii>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
constexpr i64 INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
constexpr float PI = 3.1415926535897932385;
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ cout << p.fi << " " << p.se; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr i32 ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
const char* yn(bool b) { return b ? "Yes" : "No"; }
# endif  // ngng628_library

using mint = modint1000000007;

int main() {
   i32 n;
   cin >> n;
   i32 m = n - 1;
   vvi graph(n);
   rep (_, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      graph[a].pb(b);
      graph[b].pb(a);
   }

   mint ans = 0;
   auto dfs = [&](auto self, i32 v, i32 p = -1) -> int {
      i32 res = 1;
      vi ts;
      for (i32 u : graph[v]) {
         if (u == p) continue;
         i32 t = self(self, u, v);
         res += t;
         ts.pb(t);
      }

      if (p != -1) ts.pb(n - res);

      mint now = mint(2).pow(n - 1) - 1;
      for (i32 t : ts) {
         now -= mint(2).pow(t) - 1;
      }
      ans += now;

      return res;
   };
   dfs(dfs, 0);
   ans /= mint(2).pow(n);
   print(ans.val());
}
