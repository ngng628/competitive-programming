# include <atcoder/modint>
# ifndef ONLINE_JUDGE
# include <nglib/atcoder.hpp>
# endif
# ifdef ngng628_library

int32 main() {
   auto _s = sc.nextWord();
   vi s(len(_s));
   transform(all(_s), s.begin(), ctoi);
   const int n = len(s);

   using mint = atcoder::static_modint<2019>;
   vec<mint> sums(n + 1, 0);
   rep (i, n) {
      sums[i + 1] = sums[i] + mint(10).pow(i) * s[n - i - 1];
   }

   vi cnt(2019, 0);
   rep (i, n + 1) {
      int val = sums[i].val();
      cnt[val] += 1;
   }

   int ans = 0;
   rep (i, 2019) {
      auto f = [](int n) { return n * (n - 1) / 2; };
      ans += f(cnt[i]);
   }

   cout << ans << endl;
}







# else

# include <bits/stdc++.h>
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
# define len(v) (int)std::size(v)
# define pb push_back
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
using int32 = int32_t;
using int64 = int64_t;
template<class T> using vec = vector<T>;
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vec<T>, greater<T>>;
using pii = pair<int, int>;
using vi = vec<int>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V>
ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> T scan(){ T t; cin >> t; return t; }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(char c){ return '0' <= c and c <= '9' ? c - '0' : -1; }
template<class T> void reverse(T& v){ reverse(all(v)); }
template<class T> auto next_permutation(T& v){ return next_permutation(all(v)); }
vi iota(int n) { vi v(n); iota(all(v), int(0)); return v; }
vi iota(int a, int b) { vi v(b - a); iota(all(v), a); return v; }
struct Scanner {
   Scanner() = default;
   int nextInt(int o = 0) const {
      char c = skip();
      int r = c - '0', sgn = 1;
      if (c == '-') sgn = -1, r = gc() & 0xf;
      else if (c == '+') r = gc() & 0xf;
      while (!isspace(c = gc())) r = 10 * r + (c & 0xf);
      return sgn * r + o;
   }
   char nextChar() const { return skip(); }
   string nextWord() const { char c = skip(); string r = {c}; while (!isspace(c = gc())) r.pb(c); return r; }
private:
   char skip() const { char c; while (isspace(c = getchar_unlocked())); return c; }
   inline char gc() const { return getchar_unlocked(); }
} sc;

# define ngng628_library
# include __FILE__
# endif