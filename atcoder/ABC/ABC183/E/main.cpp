/**
 *  AtCoder Beginner Contest
**/
// >>> ngng628's library 
// >>> includes 
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
// <<<
// >>> macros
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
// >>> modint
template<int MOD> struct modint {
   long long val;
   constexpr modint(long long v = 0) noexcept : val(v % MOD) { if (val < 0) val += MOD; }
   constexpr int getmod() { return MOD; }
   constexpr modint inv() { return modint(1) / modint(*this); }
   constexpr modint operator - () const noexcept { return val ? MOD - val : 0; }
   constexpr modint operator + (const modint& r) const noexcept { return modint(*this) += r; }
   constexpr modint operator - (const modint& r) const noexcept { return modint(*this) -= r; }
   constexpr modint operator * (const modint& r) const noexcept { return modint(*this) *= r; }
   constexpr modint operator / (const modint& r) const noexcept { return modint(*this) /= r; }
   constexpr modint& operator += (const modint& r) noexcept {
      val += r.val;
      if (val >= MOD) val -= MOD;
      return *this;
   }
   constexpr modint& operator -= (const modint& r) noexcept {
      val -= r.val;
      if (val < 0) val += MOD;
      return *this;
   }
   constexpr modint& operator *= (const modint& r) noexcept {
      val = val * r.val % MOD;
      return *this;
   }
   constexpr modint& operator /= (const modint& r) noexcept {
      long long a = r.val, b = MOD, u = 1, v = 0;
      while (b) {
         long long t = a / b;
         a -= t * b; swap(a, b);
         u -= t * v; swap(u, v);
      }
      val = val * u % MOD;
      if (val < 0) val += MOD;
      return *this;
   }
   constexpr bool operator == (const modint& r) const noexcept { return this->val == r.val; }
   constexpr bool operator != (const modint& r) const noexcept { return this->val != r.val; }
   friend constexpr modint<MOD> modpow(const modint<MOD> &a, long long n) noexcept {
      if (n == 0) return 1;
      auto t = modpow(a, n / 2);
      t = t * t;
      if (n & 1) t = t * a;
      return t;
   }
   friend constexpr ostream& operator << (ostream &os, const modint<MOD>& x) noexcept { return os << x.val; }
   friend constexpr istream& operator >> (istream &is, modint<MOD>& x) noexcept {
      istream& ret = is >> x.val;
      x.val %= MOD;
      return ret;
   }
};
// <<<
static const int MOD = 1000000007;
using mint = modint<MOD>;

int32_t main() {
   int H, W;
   cin >> H >> W;
   vs S(H+1, string(W+1, '*'));
   reps (y, H) {
      string s;
      cin >> s;
      S[y].replace(1, W, s);
   }

   vector<vector<mint>>  dp(H+1, vector<mint>(W+1, 0));
   vector<vector<mint>> row(H+1, vector<mint>(W+1, 0));
   vector<vector<mint>> col(H+1, vector<mint>(W+1, 0));
   vector<vector<mint>> sla(H+1, vector<mint>(W+1, 0));

   dp[1][1] = row[1][1] = col[1][1] = sla[1][1] = 1;
   reps (y, H) reps (x, W) {
      if (S[y][x] == '#') {
         dp[y][x] = sla[y][x] = col[y][x] = row[y][x] = 0;
      }
      else {
         dp[y][x] += sla[y-1][x-1];
         dp[y][x] += col[y-1][x];
         dp[y][x] += row[y][x-1];

         sla[y][x] = sla[y-1][x-1] + dp[y][x];
         col[y][x] = col[y-1][x] + dp[y][x];
         row[y][x] = row[y][x-1] + dp[y][x];
      }
   }

   print(dp[H][W]);

   return 0;
}

