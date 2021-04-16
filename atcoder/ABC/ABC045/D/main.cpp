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

struct phash {
   inline size_t operator ()(const pair<int,int>& p) const {
       const auto h1 = hash<int>()(p.first);
       const auto h2 = hash<int>()(p.second);
       return h1 ^ (h2 << 1);
   }
};

int32_t main() {
   int h, w, n;
   cin >> h >> w >> n;
   vi a(n), b(n);
   rep (i, n) cin >> a[i] >> b[i];

   unordered_set<pii, phash> st;
   unordered_map<pii, int, phash> mp;
   rep (i, n) {
      reprs (dy, -2, 2) reprs (dx, -2, 2) {
         pii p = {a[i] + dy, b[i] + dx};
         if (p.fi <= 0 or p.fi > h or p.se <= 0 or p.se > w) continue;
         if (dy == 0 and dx == 0) {
            st.insert(p);
            mp[p] = 1;
         }
         else {
            st.insert(p);
            mp[p] = mp[p] ? 1 : 0;
         }
      }
   }

   vi ans(10, 0);
   int tot = (h-2) * (w - 2);
   for (auto p : st) {
      auto add = [](const pii& p, int i, int j) -> pii { return {p.fi + i, p.se + j}; };
      int cnt = 0;
      rep (i, 3) rep (j, 3) {
         if (p.fi + i > h or p.se + j > w) goto EXIT;
         cnt += mp[add(p, i, j)];
      }
      ans[cnt]++;
      if (cnt >= 1) tot--;
      EXIT:;
   }
   ans[0] = tot;
   print(ans);
}