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
struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

int powi(int x, int n) {
   int p = 1;
   while (n > 0) {
       if (n & 1) p *= x;
       x *= x;
       n >>= 1;
   }
   return p;
}

struct Solver {
   void solve() {
      int n;
      cin >> n;

      vec<pii> pairs;
      rep (i, n) {
         repr (j, i+1, n) {
            pairs.eb(i, j);
         }
      }

      int mn = INF;
      rep (mask, powi(3, len(pairs))) {
         vi points(n, 0);
         vi ans;
         int cnt = 0;
         rep (i, len(pairs)) {
            int r = (mask / powi(3, i)) % 3;
            if (r == 0) {
               points[pairs[i].fi] += 3;
               points[pairs[i].se] += 0;
               ans.pb(1);
            } 
            else if (r == 1) {
               points[pairs[i].fi] += 0;
               points[pairs[i].se] += 3;
               ans.pb(-1);
            }
            else {
               cnt++;
               points[pairs[i].fi] += 1;
               points[pairs[i].se] += 1;
               ans.pb(0);
            }
         }
         int same = points[0];
         bool ok = true;
         rep (i, n) {
            if (same != points[i]) {
               ok = false;
               break;
            }
         }
         if (ok and chmin(mn, cnt)) {
            rep (i, len(ans)) {
               printf("%2lld | %2lld\n", i + 1, ans[i]);
            }
         }
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
