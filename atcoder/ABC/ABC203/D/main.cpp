# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(int)(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
using namespace std;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
using vs = vec<string>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(const char c){ return '0' <= c and c <= '9' ? (c - '0') : -1; }
# endif  // ngng628_library

template <class Type>
vec<vec<Type>> cumsum(const vec<vec<Type>>& a) {
   int h = len(a);
   int w = len(a[0]);
   vec<vec<Type>> sums(h+1, vec<Type>(w+1, Type(0)));
   rep (y, h) rep (x, w) {
      sums[y+1][x+1] = sums[y][x+1] + sums[y+1][x] - sums[y][x] + a[y][x];
   }
   return sums;
}

template <class Type>
Type query(const vec<vec<Type>>& sums, int x1, int x2, int y1, int y2) {
   return sums[x2][y2] - sums[x1][y2] - sums[x2][y1] + sums[x1][y1];
}

int32_t main() {
   int n, k;
   cin >> n >> k;
   vvi a(n, vi(n));
   cin >> a;

   // 答えは x 以下ですか？
   int ok = INF;
   int ng = -1;
   while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      auto isOK = [&](int key) {
         vvi b(n, vi(n));
         rep (i, n) rep (j, n) {
            b[i][j] = (int)(a[i][j] > key);
         }
         auto sums = cumsum(b);
         rep (i, n - k + 1) rep (j, n - k + 1) {
            if (query(sums, i, i + k, j, j + k) < k*k / 2 + 1) return true;
         }
         return false;
      };
      if (isOK(mid)) ok = mid;
      else ng = mid;
   }

   print(ok);
}
