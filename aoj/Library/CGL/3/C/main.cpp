# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define loop for(;;)
# define step(n) rep(_,n)
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
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
struct Setup_io { Setup_io(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

constexpr float EPS = 1e-9;
constexpr float PI = 3.1415926535897932385;
[[nodiscard]] constexpr bool eq(float a, float b){ return abs(a - b) <= EPS; }
[[nodiscard]] constexpr float to_rad(float deg){ return deg * PI / 180.0; }
[[nodiscard]] constexpr float operator ""_deg(float deg){ return to_rad(deg); }
[[nodiscard]] constexpr float to_deg(float rad){ return rad * 180.0 / PI; }

struct Vec2 {
using Point = Vec2;

   float x, y;
 
   Vec2() = default;
   constexpr Vec2(float _x, float _y) : x(_x), y(_y) {}
 
   [[nodiscard]] constexpr float length() const { return hypotl(x, y); }
   [[nodiscard]] constexpr float square_length() const { return x*x + y*y;; }
   void set_length(float s) { float t = length(); x *= s / t; y *= s / t; }

   Vec2 unit() { return *this / length(); }
   Vec2 normal() { return {-y, x}; }

   [[nodiscard]] constexpr bool is_orthogonal_to(const Vec2& other) const { return eq(dot(other), 0); }
   [[nodiscard]] constexpr bool is_parallel_to(const Vec2& other) const { return eq(cross(other), 0); }
 
   constexpr void rotate(float theta) {
      int t = x;
      x = t*cosl(theta) - y*sinl(theta);
      y = t*sinl(theta) + y*cosl(theta);
   }
 
   constexpr void rotate(float theta, const Vec2& p) { rotate(theta, p.x, p.y); }
 
   constexpr void rotate(float theta, float a, float b) {
      x -= a; y -= b;
      int t = x;
      x = t*cosl(theta) - y*sinl(theta);
      y = t*sinl(theta) + y*cosl(theta);
      x += a; y += b;
   }
 
   [[nodiscard]] constexpr float dot(const Vec2& other) const { return x*other.x + y*other.y; }
   [[nodiscard]] constexpr float cross(const Vec2& other) const { return x*other.y - y*other.x; }

   [[nodiscard]] constexpr bool intersects(const Vec2& other) const { return *this == other; }

   [[nodiscard]] friend constexpr int ccw(const Vec2& a, Vec2 b, Vec2 c) {
      b -= a, c -= a;

      // a --> b --> c で反時計回り
      if (b.cross(c) > EPS) return 1;
      // a --> b --> c で時計回り
      else if (b.cross(c) < -EPS) return -1;
      // c --> a --> b で直線上
      else if (b.dot(c) < 0) return 2;
      // a --> b --> c で直線上
      else if (b.square_length() < c.square_length()) return -2;
      // a --> c --> b で直線上
      else return 0;
   }
 
   constexpr Vec2 operator +() const { return *this; }
   constexpr Vec2 operator -() const { return{ -x, -y }; }
   constexpr Vec2 operator +(const Vec2& other) const { return{ x + other.x, y + other.y }; }
   constexpr Vec2 operator -(const Vec2& other) const { return{ x - other.x, y - other.y }; }
   constexpr Vec2 operator *(float s) const { return{ x * s, y * s }; }
   constexpr Vec2 operator /(float s) const { return{ x / s, y / s }; }
   friend inline constexpr Vec2 operator *(float s, const Vec2& v) { return{ s*v.x, s*v.y }; }
 
   constexpr Vec2& operator +=(const Vec2& other) { x += other.x; y += other.y; return *this; }
   constexpr Vec2& operator -=(const Vec2& other) { x -= other.x; y -= other.y; return *this; }
   constexpr Vec2& operator *=(float s) { x *= s; y *= s; return *this; }
   constexpr Vec2& operator /=(float s) { x /= s; y /= s; return *this; }

   friend inline constexpr bool operator ==(const Vec2& a, const Vec2& b) { return eq(a.x, b.x) and eq(a.y, b.y); }
 
   friend istream& operator >>(istream& is, Vec2& v) { return is >> v.x >> v.y; }
   friend ostream& operator <<(ostream& os, const Vec2& v) { return os << v.x << " " << v.y; }
};
using Point = Vec2;

struct Polygon {
   Polygon() = default;

   // 反時計回り
   Polygon(const vec<Point>& v) : vers(v) {}

   [[nodiscard]] float area() const {
      float res = 0;
      const int n = len(vers);
      rep (i, n - 1) res += vers[i].cross(vers[i + 1]);
      res += vers[n - 1].cross(vers[0]);
      return res * 0.5;
   }

   // 凸包判定
   [[nodiscard]] bool is_convex() const {
      const int n = len(vers);
      rep (i, n) {
         int pre = (i - 1 + n) % n;
         int now = i;
         int nxt = (i + 1) % n;

         if (ccw(vers[pre], vers[now], vers[nxt]) == -1) return false;
      }
      return true;
   }

   // 含まれる: 0, 辺の上: 1, 含まれない: 0
   [[nodiscard]] int contains(const Point& p) const {
      bool in = false;
      const int n = len(vers);
      rep (i, n) {
         Point a = vers[i] - p;
         Point b = vers[(i + 1) % n] - p;
         if (a.y > b.y) swap(a, b);
         if (a.y <= EPS and EPS < b.y and a.cross(b) < -EPS) in ^= true;
         if (eq(a.cross(b), 0) and a.dot(b) <= EPS) {
            return 1;
         }
      }
      return in ? 2 : 0;
   }

   vec<Point> vers;
};

int32_t main() {
   int n;
   cin >> n;
   vec<Point> p(n);
   cin >> p;
   Polygon poly(p);

   int Q;
   cin >> Q;
   while (Q--) {
      Point p;
      cin >> p;
      cout << poly.contains(p) << endl;
   }
}