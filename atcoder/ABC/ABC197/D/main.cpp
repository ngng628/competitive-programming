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
# endif  // ngng628_library

struct Setup_io {
   Setup_io() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
      cout << fixed << setprecision(15);
   }
} setup_io;

template <class Type = float>
struct Vec2 {
   Type x, y;

   Vec2() = default;
   constexpr Vec2(Type _x, Type _y) : x(_x), y(_y) {}

   constexpr Type length() const { return hypotl(x, y); }
   void set_length(Type s) { Type t = length(); x *= s / t; y *= s / t; }

   constexpr void rotate(float theta) {
      int t = x;
      x = t*cosl(theta) - y*sinl(theta);
      y = t*sinl(theta) + y*cosl(theta);
   }

   constexpr void rotate(float theta, Vec2 p) {
      rotate(theta, p.x, p.y);
   }

   constexpr void rotate(float theta, Type a, Type b) {
      x -= a; y -= b;
      int t = x;
      x = t*cosl(theta) - y*sinl(theta);
      y = t*sinl(theta) + y*cosl(theta);
      x += a; y += b;
   }

   constexpr Type dot(const Vec2& other) const { return x*other.x + y*other.y; }
   constexpr Type cross(const Vec2& other) const { return x*other.y - y*other.x; }

   constexpr Vec2 operator +() const { return *this; }
   constexpr Vec2 operator -() const { return{ -x, -y }; }
   constexpr Vec2 operator +(const Vec2& other) const { return{ x + other.x, y + other.y }; }
   constexpr Vec2 operator -(const Vec2& other) const { return{ x - other.x, y - other.y }; }
   constexpr Vec2 operator *(Type s) const { return{ x * s, y * s }; }
   constexpr Vec2 operator /(Type s) const { return{ x / s, y / s }; }
   friend inline constexpr Vec2 operator *(Type s, const Vec2& v) { return{ s*v.x, s*v.y }; }

   Vec2& operator +=(const Vec2& other) { x += other.x; y += other.y; return *this; }
   Vec2& operator -=(const Vec2& other) { x -= other.x; y -= other.y; return *this; }
   Vec2& operator *=(Type s) { x *= s; y *= s; return *this; }
   Vec2& operator /=(Type s) { x /= s; y /= s; return *this; }

   friend istream& operator >>(istream& is, Vec2& v) { return is >> v.x >> v.y; }
   friend ostream& operator <<(ostream& os, const Vec2& v) { return os << v.x << " " << v.y; }
};

int32_t main() {
   int n;
   cin >> n;
   Vec2 p0, pn2;
   cin >> p0 >> pn2;

   const Vec2 origin = p0;
   float r = (pn2 - p0).length() / 2;
   float t = -(M_PI / n) * (n/2 - 1);

   pn2.rotate(t, origin);
   pn2 -= origin;
   pn2.set_length(2.0 * r * sinl(M_PI / n));
   pn2 += origin;

   print(pn2);
}