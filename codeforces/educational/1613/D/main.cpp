# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (int)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
struct Setup_io { Setup_io(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

namespace BitOperations {
   constexpr int popcount(int x) { return __builtin_popcountll(x); }
   constexpr int parity(int x) { return __builtin_parityll(x); }
   constexpr int ffs(int x) { return __builtin_ffsll(x); }
   constexpr int clz(int x) { return __builtin_clzll(x); }
   constexpr int ctz(int x) { return __builtin_ctzll(x); }

   constexpr int bit(int x) { return 1LL << x; }
   constexpr int isbit(int x) { return x and (x & -x) == x; }
   constexpr int msb(int x) { return x == 0 ? -1 : 63 - clz(x); }
   constexpr int lsb(int x) { return x == 0 ? 64 : ctz(x); }
   constexpr int allbit(int x) { return (1LL << (x + 1)) - 1; }
   constexpr bool stand(int x, int i) { return (x >> i) & 1; }
}
using namespace BitOperations;

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
static const int MOD = 998244353;
using mint = modint<MOD>;

template <class Type>
struct mexset {
   mexset() { 
      s.emplace(numeric_limits<Type>::min(), numeric_limits<Type>::min());
      s.emplace(numeric_limits<Type>::max(), numeric_limits<Type>::max());
   }
   mexset(Type inf, Type sup) { s.emplace(inf, inf), s.emplace(sup, sup); }

   bool contains(const Type x) const {
      auto it = prev(s.lower_bound({x + 1, x + 1}));
      auto [l, u] = *it;
      return l <= x && x <= u;
   }

   bool insert(const Type x) {
      auto nit = s.lower_bound({x + 1, x + 1});
      auto it = prev(nit);
      auto [l, u] = *it;
      auto [nl, nu] = *nit;
      if (l <= x && x <= u) {
         mset.insert(x);
         return false;
      }

      if (u == x - 1) {
         if (nl == x + 1) s.erase(it), s.erase(nit), s.emplace(l, nu);
         else s.erase(it), s.emplace(l, x);
      }
      else {
         if (nl == x + 1) s.erase(nit), s.emplace(x, nu);
         else s.emplace(x, x);
      }
      return true;
   }

   bool erase(const Type x) {
      auto it0 = mset.find(x);
      if (it0 != mset.end()) {
         mset.erase(it0);
         return true;
      }
      auto it = prev(s.lower_bound({x + 1, x + 1}));
      auto [l, u] = *it;
      if (x < l || u < x) return false;

      s.erase(it);
      if (x == l and l < u) s.emplace(l + 1, u);
      else if (x == u and l < u) s.emplace(l, u - 1);
      else s.emplace(l, x - 1), s.emplace(x + 1, u);
      return true;
   }

   Type mex(const Type inf = 0) const {
      auto [l, u] = *prev(s.lower_bound({inf + 1, inf + 1}));
      if (l <= inf && inf <= u) return u + 1;
      else return inf;
   }

private:
   set<pair<Type, Type>> s;
   multiset<Type> mset;
};

struct Solver {
   void solve() {
      int n;
      cin >> n;
      vi a(n);
      cin >> a;

      mint ans = 0;
      rep (mask, 1, bit(n)) {
         deque<int> x;
         rep (i, n) {
            if (stand(mask, i)) {
               x.pb(a[i]);
            }
         }

         mexset<int> ms;
         bool ok = true;
         rep (i, len(x)) {
            ms.insert(x[i]);
            int m = ms.mex();
            rep (k, i + 1) {
               if (abs(x[k] - m) > 1) ok = false;
            }
         }

         ans += int(ok);
      }

      cout << ans << '\n';
   }
};

int32_t main() {
   int t;
   cin >> t;
   rep (t) {
      Solver solver;
      solver.solve();
   }
}
