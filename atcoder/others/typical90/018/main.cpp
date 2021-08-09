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
# define rreps(i,n) for(int i=(n); i>0; --i)
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

struct Setup_io {
   Setup_io() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
      cout << fixed << setprecision(15);
   }
} setup_io;

template <class Type = float>
struct Vec3 {
   Type x, y, z;

   Vec3() = default;
   constexpr Vec3(Type _x, Type _y, Type _z) : x(_x), y(_y), z(_z) {}

   constexpr Type length() const { return sqrtl(x*x + y*y + z*z); }
   constexpr Type dot(const Vec3& other) const { return x*other.x + y*other.y + z*other.z; }
   constexpr Vec3 cross(const Vec3& other) const { 
      int a = y*other.z - z*other.y;
      int b = z*other.x - x*other.z;
      int c = x*other.y - y*other.z;
      return {a, b, c};
   }

   constexpr Vec3 operator +() const { return *this; }
   constexpr Vec3 operator -() const { return{ -x, -y, -z }; }
   constexpr Vec3 operator +(const Vec3& other) const { return{ x + other.x, y + other.y, z + other.z }; }
   constexpr Vec3 operator -(const Vec3& other) const { return{ x - other.x, y - other.y, z - other.z }; }
   constexpr Vec3 operator *(Type s) const { return{ x * s, y * s, z * s }; }
   constexpr Vec3 operator /(Type s) const { return{ x / s, y / s, z / s }; }
   friend inline constexpr Vec3 operator *(Type s, const Vec3& v) { return{ s*v.x, s*v.y, s*v.z }; }

   Vec3& operator +=(const Vec3& other) { x += other.x; y += other.y; z += other.z; return *this; }
   Vec3& operator -=(const Vec3& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
   Vec3& operator *=(Type s) { x *= s; y *= s; z *= s; return *this; }
   Vec3& operator /=(Type s) { x /= s; y /= s; z *= s; return *this; }

   friend istream& operator >>(istream& is, Vec3& v) { return is >> v.x >> v.y >> v.z; }
   friend ostream& operator <<(ostream& os, const Vec3& v) { return os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; } 
};

int32_t main() {
   const float zero = 0.0;
   const float Pi = acosl(-1);
   const float TwoPi = 2.0*Pi;
   auto to_deg = [&](float t) { return t * 180.0 / Pi; };
   int T;
   cin >> T;
   int L, X, Y;
   cin >> L >> X >> Y;
   int Q;
   cin >> Q;

   Vec3 a(float(X), float(Y), zero);
   auto b = [&](float t) -> Vec3<float> {
      const float HalfL = float(L) / 2;
      float x = 0.0;
      float y = -HalfL * sinl(TwoPi / T * t);
      float z = HalfL - HalfL * cos(TwoPi / T * t);
      return {x, y, z};
   };

   while (Q--) {
      int E;
      cin >> E;
      Vec3 c = b(E) - a;
      Vec3 d(c.x, c.y, zero);
      auto [u, v, w] = d - c;
      if (abs(u) <= EPS and abs(v) <= EPS and abs(w) <= EPS) {
         print(zero);
      }
      else {
         float theta = acosl(d.dot(c) / (d.length() * c.length()));
         print(to_deg(theta));
      }
   }
}