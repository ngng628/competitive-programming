# ifndef Fruitstart_Library
# define Fruitstart_Library
# include <algorithm>
# include <cstdint>
# include <cassert>
# include <cmath>
# include <cstdio>
# include <deque>
# include <iomanip>
# include <iostream>
# include <map>
# include <queue>
# include <set>
# include <stack>
# include <unordered_map>
# include <unordered_set>
# include <utility>
# include <vector>
# include <cfloat>
# include <bitset>
# define overload3(_1, _2, _3, name, ...) name
# define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
# define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
# define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
# define reps(i, n) for (ll i = 1; i <= (ll)(n); ++i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (ll)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using ll = long long;
using i64 = long long;
using lint = int64_t;
using uint = uint32_t;
using ulint = uint64_t;
template<class T> using vec = vector<T>;
template<class T> using vector2d=vector<vector<T>>;
using pii = pair<ll, ll>;
using vi = vec<ll>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr ll oo = (1LL<<62)-(1LL<<31);
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
template <class T>
void OutVec(const vector<T>& vec){
   for(int i = 0; i < vec.size() - 1; ++i){
      cout<<vec[i]<<" ";
   }
   cout<<vec.back()<<endl;
}

template <class T>
void OutVec2d(const vector2d<T>& vec){
   for(auto v:vec){
      OutVec(v);
   }
}
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
template<class T> constexpr bool UpdateMax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool UpdateMin(T& a, const T& b){ return a > b && (a = b, true); }
struct Setup_io {
Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(16); } } setup_io;
# endif   // Fruitstart_Library

bool Main() {
   int h, w;
   cin >> h >> w;
   if (!(h | w)) return false;
   vec<string> s(h);
   cin >> s;
   auto over = [&h, w](int y, int x) { return y < 0 or y >= h or x < 0 or x >= w; };
   pair<int, int> dydx[4][3] = {
      {make_pair(0, 0), make_pair(1, 0), make_pair(1, 1)},
      {make_pair(0, 0), make_pair(0, 1), make_pair(1, 1)},
      {make_pair(1, 0), make_pair(0, 1), make_pair(1, 1)},
      {make_pair(0, 0), make_pair(1, 0), make_pair(0, 1)},
   };

   int ans = 0;

   auto dfs = [&](auto&& self, vec<string> board, int y, int x) {
      printf("===========================\n");
      rep (i, h) {
         cout << board[i] << endl;
      }
      if (y >= h and x >= w) {
         bool ok = true;
         rep (y, h) rep(x, w) {
            if (board[y][x] == '.') {
               ok = false;
               break;
            }
         }
         if (ok) ans++;
         return;
      }

      if (x >= w) {
         self(self, board, y + 1, 0);
      }

      rep (t, 4) {
         for (auto [dy, dx] : dydx[t]) if (over(y + dy, x + dx)) goto EXIT;
         for (auto [dy, dx] : dydx[t]) if (board[y + dy][x + dx] != '.') {
            
            goto EXIT;
         }

         for (auto [dy, dx] : dydx[t]) {
            board[y + dy][x + dx] = '0' + t;
         }
         self(self, board, y, x + 1);
         for (auto [dy, dx] : dydx[t]) {
            board[y + dy][x + dx] = '.';
         }

         EXIT:;
      }
   };

   dfs(dfs, s, 0, 0);

   cout << ans << endl;

   return true;
}

int main() {
   while (Main());
}
