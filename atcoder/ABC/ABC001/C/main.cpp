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
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vb = vec<bool>;
using vvb = vec<vb>;
using vvvb = vec<vvb>;
using vs = vec<string>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 5e-5;
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> T scan() { T ret; cin >> ret; return ret; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.fi << " " << p.se; return os; }
template<class T, class U, class V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t){ os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
# endif  // ngng628_library

int32_t main() {
   int deg, dis;
   cin >> deg >> dis;
   deg *= 10;
   int speed = round(((float) dis / 60.0 + EPS) * 10.0 + EPS);

   pair<string, int> ans;
   if (1125 <= deg and deg < 3375) ans.fi = "NNE";
   else if (3375 <= deg and deg < 5625) ans.fi = "NE";
   else if (5625 <= deg and deg < 7875) ans.fi = "ENE";
   else if (7875 <= deg and deg < 10125) ans.fi = "E";
   else if (10125 <= deg and deg < 12375) ans.fi = "ESE";
   else if (12375 <= deg and deg < 14625) ans.fi = "SE";
   else if (14625 <= deg and deg < 16875) ans.fi = "SSE";
   else if (16875 <= deg and deg < 19125) ans.fi = "S";
   else if (19125 <= deg and deg < 21375) ans.fi = "SSW";
   else if (21375 <= deg and deg < 23625) ans.fi = "SW";
   else if (23625 <= deg and deg < 25875) ans.fi = "WSW";
   else if (25875 <= deg and deg < 28125) ans.fi = "W";
   else if (28125 <= deg and deg < 30375) ans.fi = "WNW";
   else if (30375 <= deg and deg < 32625) ans.fi = "NW";
   else if (32625 <= deg and deg < 34875) ans.fi = "NNW";
   else ans.fi = "N";

   if (0 <= speed and speed <= 2) ans.se = 0;
   else if (3 <= speed and speed <= 15) ans.se = 1;
   else if (16 <= speed and speed <= 33) ans.se = 2;
   else if (34 <= speed and speed <= 54) ans.se = 3;
   else if (55 <= speed and speed <= 79) ans.se = 4;
   else if (80 <= speed and speed <= 107) ans.se = 5;
   else if (108 <= speed and speed <= 138) ans.se = 6;
   else if (139 <= speed and speed <= 171) ans.se = 7;
   else if (172 <= speed and speed <= 207) ans.se = 8;
   else if (208 <= speed and speed <= 244) ans.se = 9;
   else if (245 <= speed and speed <= 284) ans.se = 10;
   else if (285 <= speed and speed <= 326) ans.se = 11;
   else if (327 <= speed) ans.se = 12;

   if (ans.se == 0) ans.fi = "C";

   print(ans);
}