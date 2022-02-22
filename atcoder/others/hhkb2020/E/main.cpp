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
# endif  // ngng628_library

using Fp = atcoder::modint1000000007;
istream& operator >>(istream& is, Fp& r){ int t; is >> t; r = t; return is; }
ostream& operator <<(ostream& os, const Fp& r){ return os << r.val(); }
Fp operator"" _fp(unsigned long long n) { return n; }

struct Imos2D {
   Imos2D() = default;
   Imos2D(int h, int w) : cnt(h + 1, vi(w + 1)) {}

   void add(int y1, int y2, int x1, int x2, int x = 1) {
      cnt[y1][x1] += x;
      cnt[y1][x2] -= x;
      cnt[y2][x1] -= x;
      cnt[y2][x2] += x;
   }

   vvi get() const {
      auto tmp = cnt;
      const int h = len(cnt) - 1;
      const int w = len(cnt[0]) - 1;
      rep (y, h + 1) reps (x, w) tmp[y][x] += tmp[y][x - 1];
      reps (y, h) rep (x, w + 1) tmp[y][x] += tmp[y - 1][x];
      tmp.pop_back();
      rep (y, len(tmp)) tmp[y].pop_back();
      return tmp;
   }

   vvi cnt;
};

int32_t main() {
   int h, w;
   cin >> h >> w;
   vec<string> s(h);
   cin >> s;
   int K = 0;
   rep (i, h) rep (j, w) K += s[i][j] == '.';

   Imos2D imos(h, w);
   rep (j, w) {
      int top = 0;
      while (top < h) {
         while (top < h and s[top][j] == '#') top += 1;
         if (top >= h) break;

         int bottom = top + 1;
         while (bottom < h and s[bottom][j] == '.') bottom += 1;

         imos.add(top, bottom, j, j + 1, bottom - top);
         top = bottom;
      }
   }

   rep (i, h) {
      int left = 0;
      while (left < w) {
         while (left < w and s[i][left] == '#') left += 1;
         if (left >= w) break;

         int right = left + 1;
         while (right < w and s[i][right] == '.') right += 1;

         imos.add(i, i + 1, left, right, right - left);
         left = right;
      }
   }

   auto cnt = imos.get();

   Fp ans = 0;
   rep (i, h) {
      rep (j, w) {
         if (s[i][j] == '#') continue;
         int c = cnt[i][j] - 1;
         ans += (2_fp).pow(K) - (2_fp).pow(K - c);
      }
   }

   cout << ans << endl;
}
