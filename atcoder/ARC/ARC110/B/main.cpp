/**
 *  AtCoder Regular Contest
**/
// >>> ngng628's library 
// >>> includes 
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
// <<<
// >>> macros
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
# define step(n) rep(_, n)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define contains(x,key) ((x).find(key) != (x).end())
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
// <<<
// >>> usings 
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using mii = map<int, int>;
using mci = map<char, int>;
using msi = map<string, int>;
// <<<
// >>> constant
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
constexpr float PI = 3.1415926535897932385;
// <<<
// >>> functions 
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
// <<<
// <<<

// >>> powint 
int powint(int x, int n) {
   int p = 1;
   while (n > 0) {
      if (n & 1) p *= x;
      x *= x;
      n >>= 1;
   }
   return p;
}
// <<<

int32_t main() {
   int n;
   cin >> n;
   string t;
   cin >> t;
   string s = "";
   while (len(s) < n+3) {
      s.append("110");
   }

   int cnt = 0;
   rep (i, 3) {
      if (s.substr(i, n) == t) {
         cnt++;
      }
   }

   int ans = cnt * (3*powint(10, 10) - n) / 3;
   int rem = n % 3;
   if (rem == 0) { 
      if (s.substr(0, n) == t) ans++;
   }
   if (rem == 1) {
      ans += cnt;
   }
   if (rem == 2) {
      if (s.substr(0, n) == t) ans++;
      if (s.substr(1, n) == t) ans++;
   }

   print(ans);
}

