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

int32_t main() {
   int n, m;
   cin >> n >> m;
   vec<tuple<int, int, int>> xyz(n);
   for (auto& [x, y, z] : xyz) cin >> x >> y >> z;

   auto solve = [&](int sgn1, int sgn2, int sgn3) -> int {
      sort(all(xyz), [&sgn1, &sgn2, &sgn3](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
         auto [ax, ay, az] = a;
         auto [bx, by, bz] = b;
         return sgn1*ax + sgn2*ay + sgn3*az < sgn1*bx + sgn2*by + sgn3*bz;
      });

      int x_sum = 0, y_sum = 0, z_sum = 0;
      rep (i, m) {
         x_sum += get<0>(xyz[i]);
         y_sum += get<1>(xyz[i]);
         z_sum += get<2>(xyz[i]);
      }

      return abs(x_sum) + abs(y_sum) + abs(z_sum);
   };

   int ans = 0;
   chmax(ans, solve(1, 1, 1));
   chmax(ans, solve(1, 1, -1));
   chmax(ans, solve(1, -1, 1));
   chmax(ans, solve(1, -1, -1));
   chmax(ans, solve(-1, 1, 1));
   chmax(ans, solve(-1, 1, -1));
   chmax(ans, solve(-1, -1, 1));
   chmax(ans, solve(-1, -1, -1));

   cout << ans << endl;
}
