# include <bits/stdc++.h>
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
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

template <class T>
struct StaticRangeSum {
   StaticRangeSum() = default;
   explicit StaticRangeSum(const vec<vec<T>>& a) {
      const int h = len(a);
      const int w = len(a[0]);
      sums.resize(h + 1, vec<T>(w + 1, 0));
      rep (i, h) rep (j, w) {
         sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + a[i][j];
      }
   }

   

   [[nodiscard]] T get(int y1, int y2, int x1, int x2) const {
      return sums[y2][x2] - sums[y1][x2] - sums[y2][x1] + sums[y1][x1];
   }

   vec<vec<T>> sums;
};

int32_t main() {
   //────────────────────────────────
   // 1. 入力
   //────────────────────────────────
   vi h(3), w(3);
   rep (i, 3) cin >> h[i] >> w[i];
   const int H = h[0], W = w[0];
   if (h[1] < h[2]) h[2] = h[1];
   if (w[1] < w[2]) w[2] = w[1];
   vvi a(H, vi(W));
   cin >> a;

   //────────────────────────────────
   // 2. 解く
   //────────────────────────────────
   pii index;
   int ans = 0;
   {
      StaticRangeSum<int> cumsum(a);
      rep (i, H - h[1] + 1) rep (j, W - w[1] + 1) {
         if (chmax(ans, cumsum.get(i, i + h[1], j, j + w[1]))) {
            index.first = i;
            index.second = j;
         }
      }
   }

   vvi b(H, vi(W, 0));
   rep (i, h[1]) rep (j, w[1]) {
      int ii = i + index.first;
      int jj = j + index.second;
      b[ii][jj] = a[ii][jj];
   }

   {
      StaticRangeSum<int> cumsum(b);
      int best_score = 0;
      rep (i, H - h[2] + 1) rep (j, W - w[2] + 1) {
         chmax(best_score, cumsum.get(i, i + h[2], j, j + w[2]));
      }
      ans -= best_score;
   }

   cout << ans << endl;
}