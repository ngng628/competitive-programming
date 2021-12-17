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
constexpr int ctoi(char c) { return c - '0'; }
# endif  // ngng628_library

constexpr int modpow(int a, int n, int mod) {
   int r = 1;
   while (n > 0) {
      if (n & 1) (r *= a) %= mod;
      (a *= a) %= mod;
      n >>= 1;
   }
   return r;
}

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
   constexpr int allbit(int x) { return (1LL << (x + 1)) - 1;}
}
using namespace BitOperations;

int32_t main() {
   //──────────────────────────────────────────────────
   // 1. 入力
   //──────────────────────────────────────────────────
   int n;
   cin >> n;
   string _x;
   cin >> _x;
   vi x(n);
   transform(all(_x), x.begin(), ctoi);

   //──────────────────────────────────────────────────
   // 2. コーナーケース
   //──────────────────────────────────────────────────
   if (all_of(all(x), iszero<int>)) return cout << 1 << endl, 0;

   //──────────────────────────────────────────────────
   // 3. f(x) (mod p+1) と f(x) (mod p-1) を前計算
   //──────────────────────────────────────────────────
   int p = count(all(x), 1);
   int fxp = 0, fxn = 0;
   rep (i, n) {
      int j = n - i - 1;
      (fxp += modpow(2, j, p + 1) * x[i]) %= p + 1;
      if (p - 1 != 0) (fxn += modpow(2, j, p - 1) * x[i]) %= p - 1;
   }

   //──────────────────────────────────────────────────
   // 4. 実際に f(x_i) を計算
   //──────────────────────────────────────────────────
   rep (i, n) {
      int j = n - i - 1;

      int fi = 0;
      if (x[i] == 0) {
         int mod = p + 1;
         (fi = fxp + modpow(2, j, mod)) %= mod;
      }
      else {
         int mod = p - 1;
         if (p - 1 != 0) fi = ((fxn - modpow(2, j, mod)) % mod + mod) % mod;
         else {
            cout << 0 << endl;
            continue;
         }
      }
      int cnt = 1;
      while (fi > 0) {
         fi %= popcount(fi);
         cnt++;
      }
      cout << cnt << endl;
   }
}