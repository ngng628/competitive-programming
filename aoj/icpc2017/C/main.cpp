# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define loop for(;;)
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
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
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
struct Setup_io { Setup_io(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

constexpr array<pair<int, int>, 8> dydx8 = {{
   {1, 0}, {0, 1}, {-1, 0}, {0, -1},
   {1, 1}, {-1, -1}, {-1, 1}, {1, -1},
}};

struct Solver {
   int h, w;
   vvi e;
   Solver(int _h, int _w, const vvi& _e) : h(_h), w(_w), e(_e) {}
   int solve() {
      auto over = [&](int y, int x) { return y < 0 or y >= h or x < 0 or x >= w; };
      int ans = 0;
      rep(Y, h) rep(X, w) reprs(height, 3, h) reprs(width, 3, w) {
         if (over(Y + height - 1, X + width - 1)) break;

         int outer_min = oo;
         int inner_max = -oo;
         repr (y, Y, Y + height) repr (x, X, X + width) {
            auto is_outer = [&](int i, int j) {
               return i == Y or j == X or i == Y + height - 1 or j == X + width - 1;
            };
            if (is_outer(y, x)) chmin(outer_min, e[y][x]);
            else chmax(inner_max, e[y][x]);
         }

         int tot = 0;
         if (outer_min > inner_max) {
            repr (y, Y, Y + height) repr (x, X, X + width) {
               auto is_outer = [&](int i, int j) {
                  return i == Y or j == X or i == Y + height - 1 or j == X + width - 1;
               };
               if (not is_outer(y, x)) tot += outer_min - e[y][x];
            }
         }
         chmax(ans, tot);
      }
      return ans;
   }
};

int32_t main() {
   loop {
      int h, w;
      cin >> h >> w;
      if (!(h | w)) break;
      vvi e(h, vi(w));
      cin >> e;
      Solver solver(h, w, e);
      auto ans = solver.solve();
      cout << ans << endl;
   }
}