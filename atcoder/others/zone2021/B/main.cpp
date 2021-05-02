# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
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
using Int = long long;
using Real = long double;
template<class T> using Vec = vector<T>;
using Pii = pair<int, int>;
using Vi = Vec<int>;
using Vvi = Vec<Vi>;
using Db = deque<bool>;
using Ddb = deque<Db>;
using Vs = Vec<string>;
constexpr Int INF = (1LL<<62)-(1LL<<31);
constexpr Real EPS = 1e-10;
template<class T> istream& operator >>(istream& is, Vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const Vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const Vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const Vec<Vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
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

struct Setup_io {
   Setup_io() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
      cout << fixed << setprecision(15);
   }
} setup_io;

int main() {
   Int N, D, H;
   cin >> N >> D >> H;
   Vi d(N), h(N);
   rep (i, N) cin >> d[i] >> h[i];

   Real ans = 0.0;
   rep (i, N) {
      Real a = Real(H - h[i]) / (D - d[i]);
      chmax(ans, max(Real(0.0), h[i] - a*d[i]));
   }

   print(ans);
}