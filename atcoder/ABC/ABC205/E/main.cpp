# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int int_fast64_t
# define float __long_double
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
using __long_double = long double;
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

void imos(vvi& s, int a, int b, int c, int d) {
   s[a][c]++;
   s[a][d]--;
   s[b][c]--;
   s[b][d]++;
}

template <class Type>
vec<vec<Type>> cumsum(const vec<vec<Type>>& a) {
   const int h = len(a);
   const int w = len(a[0]);
   vec<vec<Type>> sums(h+1, vec<Type>(w+1, Type(0)));
   rep (y, h) rep (x, w) {
      sums[y+1][x+1] = sums[y][x+1] + sums[y+1][x] - sums[y][x] + a[y][x];
   }
   return sums;
}

template <class Type>
Type query(const vec<vec<Type>>& sums, int y1, int y2, int x1, int x2) {
   return sums[y2][x2] - sums[y1][x2] - sums[y2][x1] + sums[y1][x1];
}

int32_t main() {
   int H, W, N;
   cin >> H >> W >> N;
   vec<array<int, 4>> abcd;
   cin >> abcd;

   vvi grid(H, vi(W, 0));
   vvi s(H, vi(W, 0));
   for (auto [a, b, c, d] : abcd) {
      imos(s, a-1, b-1, c-1, d-1);
   }
   auto sums = cumsum(s);
   eprint("sums", sums);

   int cnt = 0;
   rep (i, H) rep (j, W) {
      if (sums[i][j] > 0) {
         cnt++;
      }
   }
   print(cnt);
}