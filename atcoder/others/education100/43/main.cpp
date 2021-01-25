/**
 *  パ研合宿2019　第3日「パ研杯2019」
**/
# ifndef ngng628  _library
# define ngng628_library
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <functional>
# include <cmath>
# include <iomanip>
# include <stack>
# include <queue>
# include <numeric>
# include <map>
# include <set>
# include <unordered_map>
# include <unordered_set>
# include <chrono>
# include <random>
# include <bitset>
# include <cassert>
# include <climits>
# define cauto const auto
# define int long long
# define float long double
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
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using mii = map<int, int>;
using mci = map<char, int>;
using msi = map<string, int>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
constexpr float PI = 3.1415926535897932385;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.FI >> p.SE; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){ cout << p.FI << " " << p.SE; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }
# endif  // ngng628 library

int32_t main() {
   /* ────────────────────────────────────
         input
      ──────────────────────────────────── */
   int H = 5;
   int W;
   cin >> W;
   vs S(H+1, string(W+1, '.'));
   reps (y, H) {
      string s;
      cin >> s;
      reps (x, W) S[y][x] = s[x-1];
   }

   mci palette;
   palette['R'] = 0; palette['B'] = 1;
   palette['W'] = 2; palette['#'] = 3;

   vector<mii> mp(W + 1);
   reps (x, W) reps (y, H) {
      mp[x][palette[S[y][x]]]++;
   }

   /* ────────────────────────────────────
         solve
      ──────────────────────────────────── */
   // i 列目を 'X' 色、 i-1 列目を 'Y' にしたときの答え
   vvvi dp(W+1, vvi(4, vi(4, INF)));
   vvvb memo(W+1, vvb(4, vb(4, false)));
   auto rec = [&](auto self, int i, int c, int d) {
      if (memo[i][c][d]) return dp[i][c][d];
      memo[i][c][d] = true;

      if (c == d or c == palette['#'] or d == palette['#']) dp[i][c][d] = INF;
      else if (i == 1) dp[i][c][d] = H - mp[i][c];
      else {
         dp[i][c][d] = H - mp[i][c] + [&]() {
            int mini = INF;
            rep (e, 4) chmin(mini, self(self, i-1, d, e));
            return mini;
         }();
      }
      return dp[i][c][d];
   };

   int ans = [&]() {
      int mini = INF;
      rep (c, 4) rep (d, 4) chmin(mini, rec(rec, W, c, d));
      return mini;
   }();

   /* ────────────────────────────────────
         output
      ──────────────────────────────────── */
   print(ans);
}
