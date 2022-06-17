# ifndef ONLINE_JUDGE
# include <nglib/atcoder.hpp>
# endif
# ifdef ngng628_library

int32 main() {
   auto n = sc.nextInt();
   auto a = sc.nextVi(n);

   int ans = 0;
   int right = 0;
   int psum = 0, xsum = 0;
   rep (left, n) {
      while (right < n and (psum + a[right]) == (xsum ^ a[right])) {
         psum += a[right];
         xsum ^= a[right];
         right += 1;
      }
      ans += right - left;
      if (right == left) right += 1;
      else {
         psum -= a[left];
         xsum ^= a[left];
      }
   }

   cout << ans << '\n';
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
   char nextChar() const { return skip(); }
   string nextWord() const { char c = skip(); string r = {c}; while (!isspace(c = gc())) r.pb(c); return r; }
   string nextLine() const { char c; string r; while ((c = gc()) != '\n') r.pb(c); return r; }
   vi nextVi(int n, int o=0) const { vi a(n); rep(i, n) a[i] = nextInt(o); return a; }
   template<size_t N> array<int, N> nextAi(int o=0) const { array<int, N> r; rep(i, N) r[i] = nextInt(o); return r; }
   template<size_t N> vec<array<int, N>> nextVecAi(int n, int o=0) const {
      vec<array<int, N>> r(n);
      rep (i, n) rep(j, N) r[i][j] = nextInt(o);
      return r;
   }
private:
   char skip() const { char c; while (isspace(c = getchar_unlocked())); return c; }
   inline char gc() const { return getchar_unlocked(); }
} sc;

# define ngng628_library
# include __FILE__
# endif