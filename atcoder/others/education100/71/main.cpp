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
# define contains(x,key) ((x).find(key) != (x).end())
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
using vpii = vec<pii>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
constexpr float PI = 3.1415926535897932385;
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ cout << p.fi << " " << p.se; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
const char* yn(bool b) { return b ? "Yes" : "No"; }
# endif  // ngng628_library

template<int MOD> struct modint {
   int val;
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
static const int MOD = 1000000007;
using mint = modint<MOD>;

struct Combination {
   vector<mint> fact, ifact;
   Combination(int n):fact(n+1),ifact(n+1) {
      assert(n < MOD);
      fact[0] = 1;
      for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
      ifact[n] = fact[n].inv();
      for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
   }
   mint operator()(int n, int k) {
      if (k < 0 || k > n) return 0;
      return fact[n]*ifact[k]*ifact[n-k];
   }
} COM(1e5);

int32_t main() {
   int n, q;
   cin >> n >> q;
   vec<mint> a(n);
   vi c(q);
   cin >> a >> c;

   vec<mint> cs(n, 0);
   reps (i, n-1) {
      cs[i] = cs[i-1] + modpow(a[i-1], a[i].val);
   }

   mint ans = 0;
   rep (i, q) {
      if (i == 0) {
         mint pre = cs[c[i]-1] - cs[0];
         ans += pre;
      }
      else {
         bool flag = false;
         if (c[i-1] > c[i]) swap(c[i-1], c[i]), flag = true;
         mint pre = cs[c[i]-1] - cs[c[i-1]-1];
         ans += pre;
         if (flag) swap(c[i-1], c[i]);
      }
   }
   mint pre = cs[c[q-1]-1] - cs[0];
   ans += pre;
   print(ans);
}
