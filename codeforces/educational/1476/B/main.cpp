# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
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
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if(sizeof...(args))cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
constexpr int ceil(int a, int b) { return (a + b - 1) / b; }
struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

// 1-index
struct FenwickTree {
   int n;
   vi bit;
   FenwickTree(int _n) : n(_n), bit(n+1, 0) {}
   FenwickTree(const vi& a) : n(len(a)), bit(len(a)+1, 0) {
      rep (i, n) add(i+1, a[i]);
   }

   void add(int i, int x) {
      assert(0 <= i and i <= n);
      if (i == 0) return;
      for (int k = i; k <= n; k += (k & -k)) bit[k] += x;
   }

   void set(int i, int x) {
      assert(0 <= i and i <= n);
      if (i == 0) return;
      int a = get(i);
      for (int k = i; k <= n; k += (k & -k)) bit[k] += x - a;
   }

   int sum(int i) {
      assert(0 <= i and i <= n);
      int s = 0;
      if (i == 0) return s;
      for (int k = i; k > 0; k -= (k & -k)) s+=bit[k];
      return s;
   }

   int sum(int l, int r) {
      return sum(r) - sum(l-1);
   }

   int get(int i) {
      assert(0 <= i and i <= n);
      return i == 0 ? 0 : sum(i) - sum(i-1);
   }

   int lower_bound(int x) {
      if (x <= 0) return 0;
      else {
         int i = 0; int r = 1;
         while (r < n) r <<= 1;
         for (int dist = r; dist > 0; dist >>= 1) {
            if (i + dist < n and bit[i + dist] < x) {
               x -= bit[i + dist];
               i += dist;
            }
         }
         return i+1;
      }
   }
};

struct Solver {
   void solve() {
      int n, k;
      cin >> n >> k;
      vi p(n+1);
      reps (i, n) cin >> p[i];
      FenwickTree ft(n);
      reps (i, n) {
         ft.add(i, p[i]);
      }

      int ans = 0;
      for (int i = 1; i < n; ++i) {
         int s = ft.sum(i-1);
         if (not (100*p[i+1] <= k*(s + p[i]))) {
            int d = ceil(100*p[i+1] - k*s - k*p[i], k);
            ft.add(i, d);
            ans += d;
         }
      }
      print(ans);
   }
};

int32_t main() {
   int t;
   cin >> t;
   while (t--) {
      Solver solver;
      solver.solve();
   }
}
