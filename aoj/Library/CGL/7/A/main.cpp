# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define overload3(_1,_2,_3,name,...) name
# define _rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep)(__VA_ARGS__)
# define _reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reps, _reprs)(__VA_ARGS__)
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
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

constexpr float EPS = 1e-9;
constexpr float PI = 3.1415926535897932385;
[[nodiscard]] constexpr bool eq(float a, float b){ return abs(a - b) <= EPS; }
[[nodiscard]] constexpr bool sgn(float a){ return (a < -EPS ? -1 : (a > EPS ? +1 : 0)); }
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

struct Circle {
   Circle() = default;

   Circle(const Point& p, float _r) : pos(p), r(_r) {}
   Circle(float x, float y, float _r) : pos(x, y), r(_r) {}

   [[nodiscard]] constexpr int intersects(const Point& p) const {
      auto sq = [](float x){ return x*x; };
      return abs(sq(pos.x - p.x) + sq(pos.y - p.y) - sq(r)) < EPS;
   }

   [[nodiscard]] constexpr int intersects(const Circle& other) const {
      return count_common_tangents(other) == 4;
   }

   [[nodiscard]] constexpr int contains(const Circle& other) const {
      return count_common_tangents(other) == 0;
   }

   [[nodiscard]] constexpr int count_common_tangents(const Circle& other) const {
      float d = (pos - other.pos).length();

      if (d > r + other.r + EPS) return 4;
      else if (eq(d, r + other.r)) return 3;
      else if (eq(d, abs(r - other.r))) return 1;
      else if (d < abs(r - other.r) - EPS) return 0;
      else return 2;
   }

   friend istream& operator >>(istream& is, Circle& c) { return is >> c.pos >> c.r; }
   friend ostream& operator <<(ostream& os, const Circle& c) { return os << c.pos << " " << c.r; }

   Point pos;
   float r;
};

struct Rect {
   Rect() = default;

   Rect(const Point& p, int _w, int _h) : pos(p), w(_w), h(_h) {}
   Rect(int x, int y, int _w, int _h) : pos(x, y), w(_w), h(_h) {}

   [[nodiscard]] constexpr int intersects(const Point& p) const {
      return abs(pos.x - p.x) <= EPS and abs(pos.x - (pos.x + w)) <= EPS and
             abs(pos.y - p.y) <= EPS and abs(pos.y - (pos.y + h)) <= EPS;
   }

   [[nodiscard]] constexpr int intersects(const Circle& c) const {
      const float a = c.pos.x;
      const float b = c.pos.y;
      float r = c.r;
      auto [x, y] = pos;

      bool ok = (abs(x - a) < EPS and abs(a - x - w) < EPS) and
                (abs(y - r - b) < EPS and abs(b - y - h - r) < EPS);
      ok |= (abs(x - r - a) < a and abs(a - x - w - r) < EPS) and
            (y < b and b < y + h);
      ok |= c.intersects({pos.x, pos.y}) or c.intersects({pos.x + w, pos.y}) or
            c.intersects({pos.x, pos.y + h}) or c.intersects({pos.x + w, pos.y + h});

      return ok;
   }


   Point pos;
   int w, h;
};

int32_t main() {
   Circle c1, c2;
   cin >> c1 >> c2;
   cout << c1.count_common_tangents(c2) << '\n';
}