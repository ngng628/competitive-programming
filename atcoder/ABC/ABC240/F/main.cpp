# ifndef ONLINE_JUDGE
# include <nglib/atcoder.hpp>
# endif
# ifdef ngng628_library

struct Solver {
   Solver() = default;

   int f(int t, int init_pos, int velocity, int acceleration) {
      return init_pos + t*velocity + (t*(t + 1) / 2)*acceleration;
   }

   int maximum(int init_pos, int velocity, int acceleration, int yi) {
      int low = 1;
      int high = yi;

      auto wrapper = [&](int t) -> int {
         return f(t, init_pos, velocity, acceleration);
      };

      while (high - low > 2) {
         int mid1 = (low + high) / 2;
         int mid2 = mid1 + 1;
         if (wrapper(mid1) < wrapper(mid2)) {
            low = mid1;
         }
         else {
            high = mid2;
         }
      }

      return max({ wrapper(1), wrapper(yi), wrapper(low + 1) });
   }

   void solve() {
      auto [n, m] = sc.nextPii();
      auto [x, y] = sc.nextPairViVi(n);
      
      int ans = -oo;
      int init_pos = 0;
      int velocity = 0;
      rep (i, n) {
         int acceleration = x[i];
         chmax(ans, maximum(init_pos, velocity, acceleration, y[i]));
         init_pos = f(y[i], init_pos, velocity, acceleration);
         velocity = velocity + y[i]*x[i];
      }

      cout << ans << endl;
   }
};

int32 main() {
   int t;
   cin >> t;
   rep (t) {
      Solver ngng628;
      ngng628.solve();
   }
}







# else

# include <bits/extc++.h>
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
using int32 = int32_t;
using int64 = int64_t;
using uint32 = uint32_t;
using uint64 = uint64_t;
using usize = size_t;
using ssize = ptrdiff_t;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using vb = basic_string<bool>;
using vvb = vec<vb>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> T scan(){ T t; cin >> t; return t; }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
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
   vi nextVi(int n, int o=0) const { vi a(n); rep(i, n) a[i] = nextInt(o); return a; }
   pii nextPii() const { return nextPii(0, 0); }
   pii nextPii(int o1, int o2) const { int a = nextInt(o1), b = nextInt(o2); return { a, b }; }
   vec<pii> nextVecPii(int n) const { return nextVecPii(n, 0, 0); }
   vec<pii> nextVecPii(int n, int o1, int o2) const { vec<pii> r(n); rep (i, n) r[i] = nextPii(o1, o2); return r; }
   pair<vi, vi> nextPairViVi(int n) const { return nextPairViVi(n, 0, 0); }
   pair<vi, vi> nextPairViVi(int n, int o1, int o2) const {
      vi a(n), b(n);
      rep (i, n) tie(a[i], b[i]) = nextPii(o1, o2);
      return { a, b };
   }
private:
   char skip() const { char c; while (isspace(c = getchar_unlocked())); return c; }
   inline char gc() const { return getchar_unlocked(); }
} sc;

# define ngng628_library
# include __FILE__
# endif