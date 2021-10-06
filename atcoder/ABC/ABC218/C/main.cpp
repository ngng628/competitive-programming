# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
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
constexpr int INF = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void drop(){ cout << '\n'; exit(0); }
template<class T, class... A> void drop(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << ' '; drop(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

vec<string> rotated(const vec<string>& s, const int t = 1);

/// <summary>
/// '#' が最初に一致する位置 origin = (i, j) を求めます。
/// </summary>
pii find_first_of_sharp(int n, const vec<string>& s) {
   rep (i, n) {
      if (auto j = s[i].find_first_of('#'); j != string::npos) {
         return make_pair(i, j);
      }
   }
   return make_pair(-1, -1);
}

/// <summary>
/// origin を原点として、'#' がある座標の集合を求めます。
/// </summary>
set<pii> make_sharps_set(int n, const vec<string>& s, pii origin) {
   auto [x, y] = origin;
   set<pii> res;
   rep (i, n) rep (j, n) {
      if (s[i][j] == '#') res.emplace(i - x, j - y);
   }
   return res;
}

struct Solver {
   int n;
   vec<string> s, t;
   Solver(int _n, const vec<string>& _s, const vec<string>& _t) : n(_n), s(_s), t(_t) {}

   // O(n**2) で s の平行移動 で t に一致させることができるか判定してください
   bool solve() {
      auto set_of_sharps_in_s = make_sharps_set(n, s, find_first_of_sharp(n, s));
      auto set_of_sharps_in_t = make_sharps_set(n, t, find_first_of_sharp(n, t));
      return set_of_sharps_in_s == set_of_sharps_in_t;
   }
};

int32_t main() {
   int n;
   cin >> n;
   vec<string> s(n), t(n);
   cin >> s >> t;

   bool ok = false;
   rep (ts, 4) {
      Solver solver(n, rotated(s, ts), t);
      ok |= solver.solve();
   }

   puts(ok ? "Yes" : "No");
}

vvi rotated(const vvi& s, const int t) {
   const int h = len(s), w = len(s[0]);
   switch ((t % 4 + 4) % 4) {
      case 0: return s;
      case 1: {
         vvi r(w, vi(h, 0));
         rep (i, w) rep (j, h) r[i][j] = s[h-1-j][i];
         return r;
      }
      case 2: {
         vvi r = s;
         rep (i, h / 2) rep (j, w) swap(r[i][j], r[h-1-i][j]);
         rep (i, h) reverse(all(r[i]));
         return r;
      }
      case 3: {
         vvi r(w, vi(h, 0));
         rep (i, w) rep (j, h) r[i][j] = s[j][w-1-i];
         return r;
      }
   }
   return vvi();
}