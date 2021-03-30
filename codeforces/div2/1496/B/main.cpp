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
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vb = vec<bool>;
using vvb = vec<vb>;
using vvvb = vec<vvb>;
using vs = vec<string>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> T scan() { T ret; cin >> ret; return ret; }
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) return os << join(v); }
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
struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

template <class Type = int>
struct mexset {
   mexset() { 
      s.emplace(numeric_limits<Type>::min(), numeric_limits<Type>::min());
      s.emplace(numeric_limits<Type>::max(), numeric_limits<Type>::max());
   }
   mexset(Type inf, Type sup) { s.emplace(inf, inf), s.emplace(sup, sup); }
 
   bool contains(const Type x) const {
      auto it = prev(s.lower_bound({x + 1, x + 1}));
      auto [l, u] = *it;
      return l <= x && x <= u;
   }
 
   bool insert(const Type x) {
      auto nit = s.lower_bound({x + 1, x + 1});
      auto it = prev(nit);
      auto [l, u] = *it;
      auto [nl, nu] = *nit;
      if (l <= x && x <= u) {
         mset.insert(x);
         return false;
      }
 
      if (u == x - 1) {
         if (nl == x + 1) s.erase(it), s.erase(nit), s.emplace(l, nu);
         else s.erase(it), s.emplace(l, x);
      }
      else {
         if (nl == x + 1) s.erase(nit), s.emplace(x, nu);
         else s.emplace(x, x);
      }
      return true;
   }
 
   bool erase(const Type x) {
      auto it0 = mset.find(x);
      if (it0 != mset.end()) {
         mset.erase(it0);
         return true;
      }
      auto it = prev(s.lower_bound({x + 1, x + 1}));
      auto [l, u] = *it;
      if (x < l || u < x) return false;
 
      s.erase(it);
      if (x == l and l < u) s.emplace(l + 1, u);
      else if (x == u and l < u) s.emplace(l, u - 1);
      else s.emplace(l, x - 1), s.emplace(x + 1, u);
      return true;
   }
 
   Type mex(const Type inf = 0) const {
      auto [l, u] = *prev(s.lower_bound({inf + 1, inf + 1}));
      if (l <= inf && inf <= u) return u + 1;
      else return inf;
   }
 
private:
   set<pair<Type, Type>> s;
   multiset<Type> mset;
};

constexpr int ceil(int a, int b) { return (a + b - 1) / b; }

struct Solver {
   void solve() {
      int n, k;
      cin >> n >> k;
      mexset S;
      set<int> st;
      int mx = 0;
      rep (i, n) {
         int a;
         cin >> a;
         S.insert(a);
         st.insert(a);
         chmax(mx, a);
      }
      if (k == 0) {
         print(len(st));
         return;
      }

      int a = S.mex();
      int b = mx;
      int add = ceil(a + b, 2);
      S.insert(add);
      st.insert(add);
      chmax(mx, add);
      if (add == a) {
         cout << len(st) + k - 1 << "\n";
      }
      else {
         cout << len(st) << "\n";
      }

   }
};

int32_t main() {
   int t;
   cin >> t;
   while (t--) {
      Solver solver;
      solver.solve();
   }
}
