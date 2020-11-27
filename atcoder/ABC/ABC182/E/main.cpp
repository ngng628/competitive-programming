//                              ______  ______  ______
// .-----..-----..-----..-----.|    __||__    ||  __  |
// |     ||  _  ||     ||  _  ||  __  ||    __||  __  |
// |__|__||___  ||__|__||___  ||______||______||______|
//        |_____|       |_____|
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <random>
#include <bitset>
#include <climits>
# define cauto const auto
# define int long long
# define float long double
# define FI first
# define SE second
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
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.FI >> p.SE; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){ cout << p.FI << " " << p.SE; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }

struct Cursor {
   Cursor() = default;
   constexpr Cursor(int _r, int _c) : r(_r), c(_c) {}

   double length() const { return r + c; }
   constexpr bool isZero() const { return r == 0 && c == 0; }
   constexpr bool over(int h, int w) const { return r < 0 or r >= h or c < 0 or c >= w; }
   constexpr Cursor rotated(const int h, const int w, const int t = 1) const {
      switch ((t % 4 + 4) % 4) {
         case 0: return { *this };
         case 1: return { c, h-1-r };
         case 2: return { h-1-r, w-1-c };
         case 3: return { w-1-c, r };
         default: return { *this };
      }
   }
   constexpr Cursor transposed() const { return { c, r }; }
   constexpr Cursor operator +() const { return *this; }
   constexpr Cursor operator -() const { return{ -r, -c }; }
   constexpr Cursor operator +(const Cursor& other) const { return{ r + other.r, c + other.c }; }
   constexpr Cursor operator -(const Cursor& other) const { return{ r - other.r, c - other.c }; }
   constexpr Cursor operator *(int s) const { return{ r*s, c*s }; }
   constexpr Cursor operator /(int s) const { return{ r/s, c/s }; }
   Cursor& operator +=(const Cursor& other) { r += other.r; c += other.c; return *this; }
   Cursor& operator -=(const Cursor& other) { r -= other.r; c -= other.c; return *this; }
   Cursor& operator *=(int s) { r *= s; c *= s; return *this; }
   Cursor& operator /=(int s) { r /= s; c /= s; return *this; }

   int r, c;
};
inline constexpr Cursor operator *(int s, const Cursor& p) { return { s*p.r, s*p.c }; }
inline ostream& operator <<(ostream& os, const Cursor& p) { return os << p.r << " " << p.c; }
inline istream& operator >>(istream& is, Cursor& p) { return is >> p.r >> p.c; }

inline constexpr int popcount(int x) { return __builtin_popcountll(x); }
inline constexpr int parity(int x) { return __builtin_parityll(x); }
inline constexpr int ffs(int x) { return __builtin_ffsll(x); }
inline constexpr int clz(int x) { return __builtin_clzll(x); }
inline constexpr int ctz(int x) { return __builtin_ctzll(x); }

vvi rotated(const vvi& s, int t = 1) {
   const int h = len(s), w = len(s[0]);
   if (t < 0) t = t % 4 + 4;
   switch (t % 4) {
      case 0: return s;
      case 1: {
         vvi r(w, vi(h));
         rep (i, w) rep (k, h) r[i][k] = s[h-k-1][i];
         return r;
      }
      case 2: {
         vvi r = s;
         rep (i, h / 2) rep (k, w) swap(r[i][k], r[h-i-1][k]);
         rep (i, h) reverse(all(r[i]));
         return r;
      }
      case 3: {
         vvi r(w, vi(h));
         rep (i, w) rep (k, h) r[i][k] = s[k][w-i-1];
         return r;
      }
   }
   return vvi();
}

void solve(vvi& S, const Cursor p, int color) {
   const int h = len(S);
   for (int y = p.r; y < h; ++y) {
      if (S[y][p.c] == -1) break;
      if (S[y][p.c] == color) break;
      S[y][p.c] = color;
   }
}

int32_t main() {
   int h, w, n, m;
   cin >> h >> w >> n >> m;
   vector<Cursor> lamp(n), wall(m);
   cin >> lamp >> wall;
   for (auto& p : lamp) p -= { 1, 1 };
   for (auto& p : wall) p -= { 1, 1 };

   vvi S(h, vi(w, 0));
   for (cauto& p : lamp) S[p.r][p.c] = 1;
   for (cauto& p : wall) S[p.r][p.c] = -1;

   rep (i, 4) {
      S = rotated(S);
      rep (k, n) {
         solve(S, lamp[k].rotated(h, w, i + 1), i + 10);
      }
   }

   int ans = 0;
   rep (i, h) ans += count_if(all(S[i]), [](int x){ return x > 0; });
   print(ans);

   return 0;
}


