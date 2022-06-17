# ifndef ONLINE_JUDGE
# include <nglib/atcoder.hpp>
# endif
# ifdef ngng628_library

class Random {
public:
   Random() : x(1859738746), y(9707750167), z(2653432786), w(3463085849) {}
 
   [[nodiscard]] int nextInt(int n) noexcept {
      uint64_t t = (x ^ (x << 11));
      x = y; y = z; z = w;
      w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
      return w % n;
   }

private:
   uint64_t x, y, z, w;
} rnd;

struct Prime {
   Prime() : n_max(0) {}
   // O ( N loglog(N) )
   Prime(int n) : n_max(n), table(n+1, true), osak(n+1) {
       iota(osak.begin(), osak.end(), 0);
       osak[0] = 1;
       if (n >= 0) table[0] = false;
       if (n >= 1) table[1] = false;
       for (int i = 2; i * i <= n; i++) {
           if (not table[i]) continue;
           for(int k = i + i; k <= n; k += i) {
               table[k] = false;
               osak[k] = i;
           }
       }
       reps (i, 2, n) if (table[i]) lst.pb(i);
   }

   // n <= n_max のとき: O(1)
   // それ超えのとき: O( sqrt(N) )
   bool is(const int n) {
       if (n <= n_max) return table[n];
       if (n <= 4) return n == 2 || n == 3;
       if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
       for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
       return true;
   }

   // O( sqrt(N) )
   map<int, int> factor(int n) {
       if (n == 1) {
           map<int, int> one;
           one[1] = 1;
           return one;
       }
       if (n <= n_max) return impl_factor_fast(n);
       map<int, int> ret;
       for (int i = 2; i * i <= n; i++) {
           while (n % i == 0) {
               ret[i]++;
               n /= i;
           }
       }
       if (n != 1) ret[n] = 1;
       return ret;
   }

   // O( log(N) )
   map<int, int> impl_factor_fast(int n) {
       map<int, int> ret;
       while (n != 1) {
           int p = osak[n];
           ret[p]++;
           n /= p;
       }
       return ret;
   }

   // O( len(v) log(v_max) )
   bool to(vi v) {
       unordered_set<int> s;
       for (auto& n : v) {
           while (n != 1) {
               int p = osak[n];
               if (s.count(p)) return false;
               else s.insert(p);
               while (n % p == 0) n /= p;
           }
       }
       return true;
   }

   const int n_max;
   vb table;
   vi osak;
   vi lst;
} PRIME(55555 * 55);

int32 main() {
   auto n = sc.nextInt();
   vi primes;
   for (auto p : PRIME.lst) {
      if (p > 55555) break;
      primes.push_back(p);
   }

   vector<int> ans;
   for (int i = 0; i < len(primes); ++i) {
      if (to_string(primes[i]).back() == '1') {
         ans.push_back(primes[i]);
      }
      if (len(ans) == n) break;
   }

   cout << ans << endl;
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
   template<size_t N> array<int, N> nextAi(int o=0) const { array<int, N> r; rep(i, N) r[i] = nextInt(o); return r; }
   template<size_t N> vec<array<int, N>> nextVecAi(int n, int o=0) const {
      vec<array<int, N>> r(n);
      rep (i, n) rep(j, N) r[i][j] = nextInt(o);
      return r;
   }
   vvi nextVvi(int n, int m, int o=0) const { vvi a(n, vi(m)); rep(i, n) rep(j, m) a[i][j] = nextInt(o); return a; }
   vec<string> nextWords(int n) const { vec<string> s(n); rep (i, n) s[i] = nextWord(); return s; }
   set<int> nextSetInt(int n, int o=0) const { set<int> r; rep(n) r.insert(nextInt(o)); return r; }
   set<char> nextSetChar(int n) const { set<char> r; rep(n) r.insert(nextChar()); return r; }
   set<string> nextSetWord(int n) const { set<string> r; rep(n) r.insert(nextWord()); return r; }
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
   char skip() const { char c; while (isspace(c = getchar_unlocked())); return c; }
   inline char gc() const { return getchar_unlocked(); }
} sc;

# define ngng628_library
# include __FILE__
# endif