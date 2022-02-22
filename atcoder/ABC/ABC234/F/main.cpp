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

struct Combination {
   vec<Fp> fact, ifact;
   Combination(int n) : fact(n + 1), ifact(n + 1) {
      assert(n < Fp::mod());
      fact[0] = 1;
      reps (i, n) fact[i] = fact[i-1] * i;
      ifact[n] = fact[n].inv();
      rreps (i, n) ifact[i-1] = ifact[i] * i;
   }
   Fp operator()(int n, int k) {
      if (k < 0 or k > n) return 0;
      return fact[n] * ifact[k] * ifact[n - k];
   }
} nchoosek(1e6 + 1);

int32_t main() {
   string s;
   cin >> s;
   const int n = len(s);

   vi cnt(26, 0);
   for (char c : s) cnt[c - 'a'] += 1;

   vec<vec<Fp>> dp(26 + 1, vec<Fp>(n + 1 + 5050, 0));
   dp[0][0] = 1;
   for (char c = 'a'; c <= 'z'; c++) {
      const int i = c - 'a';
      rep (j, n + 1) {
         rep (k, cnt[i] + 1) {
            dp[i + 1][j + k] += dp[i][j] * nchoosek(j + k, k);
         }
      }
   }

   Fp ans = 0;
   reps (i, n) {
      ans += dp[26][i];
   }
   cout << ans << '\n';
}