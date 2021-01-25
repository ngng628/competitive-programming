# include <bits/stdc++.h>
# include <atcoder/all.h>
# ifndef ngng628_library
# define ngng628_library
# define cauto const auto
# define fi first
# define se second
# define mkp make_pair
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
# define contains(x,key) ((x).find(key) != (x).end())
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
using namespace atcoder;
using ll = int64_t;
using ld = long double;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using mii = map<ll, ll>;
using mci = map<char, ll>;
using msi = map<string, ll>;
constexpr ll INF = (1LL<<62)-(1LL<<31);
constexpr ld EPS = 1e-10;
constexpr ld PI = 3.1415926535897932385;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ cout << p.fi << " " << p.se; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }
# endif  // ngng628_library

using mint = static_modint<10007>;

constexpr int Flag(int n) {
   return 1LL << n;
}

map<char, int> mapping = {{'J', Flag(0)}, {'O', Flag(1)}, {'I', Flag(2)}};
auto read() {
   int n;
   cin >> n;
   vi a(n+1);
   a[0] = mapping['J'];
   reps (i, n) {
      char c;
      cin >> c;
      a[i] = mapping[c];
   }
   return make_tuple(n, a);
}

int32_t main() {
   auto [n, a] = read();

   vector dp(n+1, vector<mint>(Flag(3), 0));
   dp[0][mapping['J']] = 1;
   reprs (i, 1, n) {
      rep (s, Flag(3)) {
         if (!(s & a[i])) dp[i][s] = 0;
         else rep (t, Flag(3)) if (s & t) dp[i][s] += dp[i-1][t];
      }
   }

   mint ans = 0;
   rep (s, Flag(3)) ans += dp[n][s];
   print(ans.val());
}
