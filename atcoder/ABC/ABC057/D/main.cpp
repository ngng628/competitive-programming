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
struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

template <class Type>
vec<Type> cumsum(const vec<Type>& a) {
   int n = len(a);
   vec<Type> sums(n+1);
   sums[0] = 0;
   reps (i, n) sums[i] = sums[i-1] + a[i-1];
   return sums;
}

struct Combination {
   vvi table;
   Combination(int n, int k) : table(n + 1, vi(k + 1)) {
      reprs (i, 0, n) reprs (j, 0, i) {
         if (!j or j == i) table[i][j] = 1;
         else table[i][j] = table[i-1][j-1] + table[i-1][j];
      }
   }

   int operator()(int n, int k) {
      if (n < k or n < 0 or k < 0) return 0;
      return table[n][k];
   }
} COM(51, 51);

int32_t main() {
   int n, a, b;
   cin >> n >> a >> b;
   vi v(n);
   cin >> v;


   sort(rall(v));

   float ave = 0.0;
   int idx = 0;
   auto sums = cumsum(v);
   reprs (i, a, b) if (chmax(ave, (float) sums[i] / i)) idx = i - 1;

   if (v[0] == v[a-1]) {
      int ans = 0;
      int cnt = count(all(v), v[0]);
      reprs (i, a, b) ans += COM(cnt, i);
      print(ave);
      drop(ans);
   }

   int cnt = count(all(v), v[idx]);
   int k = 0;
   reprs (i, 0, idx) if (v[i] == v[idx]) k++;

   print(ave);
   print(COM(cnt, k));
}