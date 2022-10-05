# pragma region Library
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
# define len(v) ssize(std::size(v))
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vec<T>, greater<T>>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
using vb = basic_string<bool>;
using vvb = vec<vb>;
using vvvb = vec<vvb>;
template<class T, size_t N> auto make_vector(vi& sizes, const T& x) {
   if constexpr (N == 1) return vector(sizes[0], x);
   else { int size = sizes[N - 1]; sizes.pop_back();
   return vector(size, make_vector<T, N - 1>(sizes, x)); }
}
template<class T, size_t N> auto make_vector(int const(&sizes)[N], const T& x = T()) {
   vi s(N); rep (i, N) s[i] = sizes[N - i - 1];
   return make_vector<T, N>(s, x);
}
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){
   rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : "");
   return os;
}
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V>
ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> T scan(){ T t; cin >> t; return t; }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(char c){ return '0' <= c and c <= '9' ? c - '0' : -1; }
template<class T> constexpr bool iseven(T n) { return !(n & 1); }
template<class T> constexpr bool isodd(T n) { return n & 1; }
template<class T> void sort(T& v){ sort(all(v)); }
template<class T, class C> void sort(T& v, C comp){ sort(all(v), comp); }
template<class T> void rsort(T& v){ sort(all(v), greater<>()); }
template<class T, class C> void rsort(T& v, C comp){ sort(rall(v), comp); }
template<class T> void reverse(T& v){ reverse(all(v)); }
template<class T> void unique(T& v){ sort(v); v.erase(unique(all(v)), end(v)); }
template<class T = int, class S> T accumulate(const S& v, T init = 0) { return accumulate(cbegin(v), cend(v), init); }
template<class T = int, class S, class Op> T accumulate(const S& v, T init, Op op) { return accumulate(cbegin(v), cend(v), init, op); }
template<class T = int, class S> auto count(const S& v, T target) { return count(cbegin(v), cend(v), target); }
template<class T, class C> auto count_if(const T& v, C comp) { return count_if(cbegin(v), cend(v), comp); }
template<class T> auto max(T& v){ return *max_element(cbegin(v), cend(v)); }
template<class T> auto min(T& v){ return *min_element(cbegin(v), cend(v)); }
template<class T = int, class S> auto lower_bound(const S& v, T x){ return lower_bound(cbegin(v), cend(v), x); }
template<class T = int, class S> auto upper_bound(const S& v, T x){ return upper_bound(cbegin(v), cend(v), x); }
template<class T> auto next_permutation(T& v){ return next_permutation(all(v)); }
vi iota(int n) { vi v(n); iota(all(v), int(0)); return v; }
vi iota(int a, int b) { vi v(b - a); iota(all(v), a); return v; }
vec<pii> iota2(int n, int m) { vec<pii> res(n * m); rep (i, n) rep (j, m) res[n*i + j] = { i, j }; return res; }
namespace math {
   template<class T> T sum(T n) { return n * (n + 1) / 2; }
   template<class T> T nc2(T n) { return n * (n - 1) / 2; }
   template<class T> T nc3(T n) { return n * (n - 1) * (n - 2) / 6; }
   template<class T> int sgn(T x) { return x == T(0) ? 0 : (x > 0) - (x < 0); }
   int pow(int a, int n) { int e = 1; while (n) { if (n & 1) e *= a; a *= a; n >>= 1; } return e; }
   int pow(int a, int n, int m) { int e = 1; a %= m; while (n) { if (n & 1) (e *= a) %= m; (a *= a) %= m; n >>= 1; } return e; }
   int ceil(const int n, const int d) { assert(d); return n / d + int((n ^ d) >= 0 && n % d != 0); }
   constexpr int floor_sqrt(int n) {
      if (n <= 1) return n;
      int r = sqrt(n);
      do r = (r & n / r) + (r ^ n / r) / 2; while (r > n / r);
      return r;
   }
}
template <class F>
struct Bind { F f; Bind(F &&f_)
   : f(forward<F>(f_)) {} template <class... Args> auto operator()(Args &&...args) const
   { return f(*this, forward<Args>(args)...); }
};
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
   template<size_t N> array<int, N> nextAi() const { array<int, N> r; rep(i, N) r[i] = nextInt(); return r; }
   template<size_t N> array<int, N> nextAi(initializer_list<int> os) const {
      vi o(all(os));
      array<int, N> r;
      rep(i, N) r[i] = nextInt(o[i]);
      return r;
   }
   template<size_t N> vec<array<int, N>> nextVecAi(int n, initializer_list<int> os) const {
      vec<array<int, N>> r(n);
      rep (i, n) r[i] = nextAi<N>(os);
      return r;
   }
   template<size_t N> vec<array<int, N>> nextVecAi(int n) const { vec<array<int, N>> r(n); rep (i, n) r[i] = nextAi<N>(); return r; }
   vvi nextVvi(int n, int m, int o=0) const { vvi a(n, vi(m)); rep(i, n) rep(j, m) a[i][j] = nextInt(o); return a; }
   vec<string> nextWords(int n) const { vec<string> s(n); rep (i, n) s[i] = nextWord(); return s; }
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
   tuple<int, int, vvi> nextGraph(int o=-1) const {
      auto [n, m] = nextPii();
      vvi g(n);
      rep (m) { auto [a, b] = nextPii(o, o); g[a].pb(b); g[b].pb(a); }
      return { n, m, g };
   }
   tuple<int, int, vvi> nextDirectedGraph(int o=-1) const {
      auto [n, m] = nextPii();
      vvi g(n);
      rep (m) { auto [a, b] = nextPii(o, o); g[a].pb(b); }
      return { n, m, g };
   }
   tuple<int, int, vvi> nextTree(int o=-1) const {
      int n = nextInt();
      vvi g(n);
      rep (n - 1) { auto [a, b] = nextPii(o, o); g[a].pb(b); g[b].pb(a); }
      return { n, n - 1, g };
   }
   tuple<int, int, vvi> nextDirectedTree(int o=-1) const {
      int n = nextInt();
      vvi g(n); rep (n - 1) { auto [a, b] = nextPii(o, o); g[a].pb(b); }
      return { n, n - 1, g };
   }
private:
   char skip() const { char c; while (isspace(c = getchar())); return c; }
   inline char gc() const { return getchar(); }
} sc;
# pragma endregion Library

struct Solver {
   Solver() = default;
   void solve(string s) {
      auto n = sc.nextInt();
      cout << n << endl;
   }
};

int32 main() {
   rep (t) {
   }
}