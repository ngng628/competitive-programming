# include <bits/stdc++.h>
# include <atcoder/modint>
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
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
using Fp = atcoder::modint998244353;
istream& operator >>(istream& is, Fp& r){ int t; is >> t; r = t; return is; }
ostream& operator <<(ostream& os, const Fp& r){ return os << r.val(); }
Fp operator"" _fp(unsigned long long n) { return n; }
# endif  // ngng628_library

namespace BitOperations {
   constexpr int Popcount(int x) { return __builtin_popcountll(x); }
   constexpr int Parity(int x) { return __builtin_parityll(x); }
   constexpr int Ffs(int x) { return __builtin_ffsll(x); }
   constexpr int Clz(int x) { return __builtin_clzll(x); }
   constexpr int Ctz(int x) { return __builtin_ctzll(x); }

   constexpr int Bit(int x) { return 1LL << x; }
   constexpr bool Isbit(int x) { return x and (x & -x) == x; }
   constexpr int Msb(int x) { return x == 0 ? -1 : 63 - Clz(x); }
   constexpr int Lsb(int x) { return x == 0 ? 64 : Ctz(x); }
   constexpr int Allbit(int n) { return (1LL << n) - 1; }
   constexpr bool Stand(int x, int i) { return x & Bit(i); }
   constexpr int Log2i(int x) { return Msb(x); }
}
using namespace BitOperations;

int32_t main() {
   string N;
   cin >> N;
   const int n = len(N);
   int m;
   cin >> m;
   vi c(m);
   cin >> c;

   vec<vec<Fp>> dp(Allbit(10) + 1, vec<Fp>(2, 0));
   vec<vec<Fp>> num(Allbit(10) + 1, vec<Fp>(2, 0));
   enum Ordering { Less, Equal };
   num[0][Equal] = 1;
   rep (i, n) {
      vec<vec<Fp>> dp2(Allbit(10) + 1, vec<Fp>(2, 0));
      vec<vec<Fp>> num2(Allbit(10) + 1, vec<Fp>(2, 0));
      const int ni = N[i] - '0';
      rep (S, Allbit(10) + 1) {
         for (int ord : { Less, Equal }) {
            rep (d, 10) {
               int S2 = S;
               int ord2 = ord;

               if (d == 0) {
                  if (S) S2 |= 1;
               }
               else  S2 |= Bit(d);

               if (ord == Equal and d > ni) continue;
               if (d < ni) ord2 = Less;

               num2[S2][ord2] += num[S][ord];
               dp2[S2][ord2] += 10*dp[S][ord] + d*num[S][ord];
            }
         }
      }
      swap(dp2, dp);
      swap(num2, num);
   }

   Fp ans = 0;
   int T = accumulate(all(c), 0, [](int acc, int d){ return acc | (1 << d); });
   rep (S, Allbit(10) + 1) {
      if ((S & T) != T) continue;
      ans += dp[S][Less] + dp[S][Equal];
   }
   cout << ans << endl;
}