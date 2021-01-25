/**
 *  AtCoder Beginner Contest 186
 **/
# ifndef ngng628_library
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
# define lb(v,x) distance(std::begin(v), lower_bound(aint(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(aint(v), (x)))
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
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){ cout << p.fi << " " << p.se; return os; }
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
# endif  // ngng628_library

// 1-index
struct FenwickTree {
   int n;
   vi bit;
   FenwickTree(int _n) : n(_n), bit(n+1, 0) {}
   FenwickTree(const vector<int>& a) : n(len(a)), bit(len(a)+1, 0) {
      rep (i, n) add(i+1, a[i]);
   }

   void add(int i, int x) {
      assert(0 <= i and i <= n);
      if (i == 0) return;
      for (int k = i; k <= n; k += (k & -k)) bit[k] += x;
   }

   void set(int i, int x) {
      assert(0 <= i and i <= n);
      if (i == 0) return;
      int a = get(i);
      for (int k = i; k <= n; k += (k & -k)) bit[k] += x - a;
   }

   int sum(int i) {
      assert(0 <= i and i <= n);
      int s = 0;
      if (i == 0) return s;
      for (int k = i; k > 0; k -= (k & -k)) s+=bit[k];
      return s;
   }

   int sum(int l, int r) {
      return sum(r) - sum(l-1);
   }

   int get(int i) {
      assert(0 <= i and i <= n);
      return i == 0 ? 0 : sum(i) - sum(i-1);
   }

   int lower_bound(int x) {
      if (x <= 0) return 0;
      else {
         int i = 0; int r = 1;
         while (r < n) r <<= 1;
         for (int dist = r; dist > 0; dist >>= 1) {
            if (i + dist < n and bit[i + dist] < x) {
               x -= bit[i + dist];
               i += dist;
            }
         }
         return i+1;
      }
   }
};

int32_t main() {
   int h, w, m;
   cin >> h >> w >> m;
   vi x(m), y(m);
   rep (i, m) {
      cin >> y[i] >> x[i];
      x[i]--; y[i]--;
   }

   // 右 ==> 下 を素直に求める
   vi xmin(h, w), ymin(w, h);
   rep (i, m) {
      chmin(xmin[y[i]], x[i]);
      chmin(ymin[x[i]], y[i]);
   }
   int xlim = xmin[0], ylim = ymin[0];
   int ans = accumulate(begin(ymin), begin(ymin) + xlim, 0LL);

   // 下 ==> 右 で新たに行けるようになる場所を求める
   vvi xs(h);
   rep (i, m) xs[y[i]].pb(x[i]);
   FenwickTree ft(w + 1);
   rep (i, ylim) {
      ans += ft.sum(1, xmin[i]);
      if (i == 0) reprs (k, xmin[i], w) ft.set(k + 1, 1);
      else for (int v : xs[i]) ft.set(v + 1, 1);
   }

   print(ans);
}
