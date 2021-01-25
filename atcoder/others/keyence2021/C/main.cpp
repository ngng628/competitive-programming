# include <bits/stdc++.h>
# include <atcoder/modint>
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

using mint = modint998244353;

int main() {
   ll H, W, K;
   cin >> H >> W >> K;
   vi h(K+1), w(K+1), c(K+1);
   map<pii, char> mp;
   reps (i, K) {
      cin >> h[i] >> w[i] >> c[i];
      mp[mkp(h[i], w[i])] = c[i];
   }

   vector<vector<mint>> dp(H+10, vector<mint>(W+10, 0));
   reps (i, H) {
      reps (j, W) {
         if (i == 1 and j == 1) {
            dp[i][j] = 1;
            continue;
         }
         char e = mp[mkp(i-1, j)];
         // 上下 {
         switch (e) {
            case 'R':
               break;
            case 'D':
               dp[i][j] += dp[i-1][j];
               break;
            case 'X':
               dp[i][j] += dp[i-1][j];
               break;
            default: // 書かれてない
               dp[i][j] += dp[i-1][j];
               break;
         }

         // 左右
         e = mp[mkp(i, j-1)];
         switch (e) {
            case 'R':
               dp[i][j] += dp[i][j-1];
               break;
            case 'D':
               break;
            case 'X':
               dp[i][j] += dp[i][j-1];
               break;
            default: // 書かれてない
               dp[i][j] += dp[i][j-1];
               break;
         }

         if (mp[mkp(i, j)] == 0) {
            dp[i][j] *= 3;
         }
      }
   }

   // reps (i, H) {
   //    reps (j, W) {
   //       cerr << dp[i][j].val() << " ";
   //    }
   //    cerr << "\n";
   // }

   mint ans = dp[H][W];
   print(ans.val());
}
