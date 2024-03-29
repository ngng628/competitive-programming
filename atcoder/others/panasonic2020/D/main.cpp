# ifndef ONLINE_JUDGE
# include <nglib/atcoder.hpp>
# endif
# ifdef ngng628_library

int32 main() {
   auto n = sc.nextInt();

   set<string> ans;
   Fix([&](auto&& Recall, string s, char mx) {
      if (len(s) == n) {
         ans.insert(s);
         return;
      }
      for (char c = 'a'; c <= mx + 1; ++c) {
         Recall(s + string(1, c), max(mx, c));
      }
   })
   ("a", 'a');

   for (auto s : ans) {
      cout << s << '\n';
   }
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
using db = deque<bool>;
using ddb = deque<db>;
using dddb = deque<ddb>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> T scan(){ T t; cin >> t; return t; }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(char c){ return '0' <= c and c <= '9' ? c - '0' : -1; }
int ceil(const int n, const int d) { assert(d); return n / d + int((n ^ d) >= 0 && n % d != 0); }
template<class T> void sort(T& v){ sort(all(v)); }
template<class T, class Compare> void sort(T& v, Compare comp){ sort(all(v), comp); }
template<class T> void rsort(T& v){ sort(all(v), greater<>()); }
template<class T, class Compare> void rsort(T& v, Compare comp){ sort(rall(v), comp); }
template<class T> void reverse(T& v){ reverse(all(v)); }
template<class T> void unique(T& v){ sort(v); v.erase(unique(all(v)), std::end(v)); }
template <class T = int, class S> T accumulate(const S& v, T init = 0) { return accumulate(std::cbegin(v), std::cend(v), init); }
template <class T = int, class S, class Operation> T accumulate(const S& v, T init, Operation op) { return accumulate(std::cbegin(v), std::cend(v), init, op); }
template <class T = int, class S> auto count(const S& v, T target) { return count(std::cbegin(v), std::cend(v), target); }
template <class T, class Compare> auto count_if(const T& v, Compare comp) { return count_if(std::cbegin(v), std::cend(v), comp); }
template<class T> auto max(T& v){ return *max_element(std::cbegin(v), std::cend(v)); }
template<class T> auto min(T& v){ return *min_element(std::cbegin(v), std::cend(v)); }
template<class T = int, class S> auto lower_bound(const S& v, T x){ return lower_bound(std::cbegin(v), std::cend(v), x); }
template<class T = int, class S> auto upper_bound(const S& v, T x){ return upper_bound(std::cbegin(v), std::cend(v), x); }
template<class T> auto next_permutation(T& v){ return next_permutation(all(v)); }
vector<int> iota(int n) { vector<int> v(n); std::iota(all(v), int(0)); return v; }
vector<int> iota(int a, int b) { vector<int> v(b - a); std::iota(all(v), a); return v; }
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
template <class F>
struct Fix {
   F f;
   Fix(F &&f_) : f(std::forward<F>(f_)) {}
   template <class... Args> auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...); }
};
struct Scanner {
   Scanner() = default;
   int nextInt(int offset = 0) const {
      char c = skip();
      int r = c - '0';
      int sgn = 1;
      if (c == '-') sgn = -1, r = gc() & 0xf;
      else if (c == '+') r = gc() & 0xf;
      while (not isspace(c = gc())) r = 10 * r + (c & 0xf);
      return sgn * r + offset;
   }
   char nextChar() const { return skip(); }   
   string nextWord() const { char c = skip(); string r = {c}; while (not isspace(c = gc())) r.push_back(c); return r; }
   string nextLine() const { char c; string r; while ((c = gc()) != '\n') r.push_back(c); return r; }
   vi nextVi(int n, int offset=0) const { vi a(n); rep(i, n) a[i] = nextInt(offset); return a; }
   template <size_t N> array<int, N> nextAi(int offset=0) const { array<int, N> r; rep(i, N) r[i] = nextInt(offset); return r; }
   template <size_t N> vec<array<int, N>> nextVecAi(int n, int offset=0) const { vec<array<int, N>> r(n); rep (i, n) rep(j, N) r[i][j] = nextInt(offset); return r; }
   vvi nextVvi(int n, int m, int offset=0) const { vvi a(n, vi(m)); rep(i, n) rep(j, m) a[i][j] = nextInt(offset); return a; }
   vec<string> nextWords(int n) const { vec<string> s(n); rep (i, n) s[i] = nextWord(); return s; }
   set<int> nextSetInt(int n, int offset=0) const { set<int> r; rep(n) r.insert(nextInt(offset)); return r; }
   set<char> nextSetChar(int n) const { set<char> r; rep(n) r.insert(nextChar()); return r; }
   set<string> nextSetWord(int n) const { set<string> r; rep(n) r.insert(nextWord()); return r; }
   pii nextPii() const { return nextPii(0, 0); }
   pii nextPii(int offset1, int offset2) const { int a = nextInt(offset1), b = nextInt(offset2); return make_pair(a, b); }
   vec<pii> nextVecPii(int n) const { return nextVecPii(n, 0, 0); }
   vec<pii> nextVecPii(int n, int offset1, int offset2) const { vec<pii> r(n); rep (i, n) r[i] = nextPii(offset1, offset2); return r; }
   pair<vi, vi> nextPairViVi(int n) const { return nextPairViVi(n, 0, 0); }
   pair<vi, vi> nextPairViVi(int n, int offset1, int offset2) const { vi a(n), b(n); rep (i, n) tie(a[i], b[i]) = nextPii(offset1, offset2); return make_pair(a, b); }
private:
   char skip() const { char c; while (isspace(c = getchar_unlocked())); return c; }
   inline char gc() const { return getchar_unlocked(); }
} sc;

# define ngng628_library
# include __FILE__
# endif