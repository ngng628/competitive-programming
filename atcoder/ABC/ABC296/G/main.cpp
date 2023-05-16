# include <bits/stdc++.h>
using namespace std;

namespace geometry {
  using Real = int;
  const Real EPS = 1e-8;
  const Real PI = acos(static_cast< Real >(-1));

  enum {
    OUT, ON, IN
  };

  inline int sign(const Real &r) {
    return r < 0 ? -1 : r > 0 ? 1 : 0;
  }

  inline bool equals(const Real &a, const Real &b) {
   return a == b;
  }
}

namespace geometry {
  using Point = complex< Real >;

  istream &operator>>(istream &is, Point &p) {
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
  }

  ostream &operator<<(ostream &os, const Point &p) {
    return os << real(p) << " " << imag(p);
  }

  Point operator*(const Point &p, const Real &d) {
    return Point(real(p) * d, imag(p) * d);
  }

  // rotate point p counterclockwise by theta rad
  Point rotate(Real theta, const Point &p) {
    return Point(cos(theta) * real(p) - sin(theta) * imag(p), sin(theta) * real(p) + cos(theta) * imag(p));
  }

  Real cross(const Point &a, const Point &b) {
    return real(a) * imag(b) - imag(a) * real(b);
  }

  Real dot(const Point &a, const Point &b) {
    return real(a) * real(b) + imag(a) * imag(b);
  }

  bool compare_x(const Point &a, const Point &b) {
    return equals(real(a), real(b)) ? imag(a) < imag(b) : real(a) < real(b);
  }

  bool compare_y(const Point &a, const Point &b) {
    return equals(imag(a), imag(b)) ? real(a) < real(b) : imag(a) < imag(b);
  }

  using Points = vector< Point >;
}

namespace geometry {
  using Polygon = vector< Point >;
  using Polygons = vector< Polygon >;
}


namespace geometry {
  int convex_polygon_contains(const Polygon &Q, const Point &p) {
    int N = (int) Q.size();
    Point g = (Q[0] + Q[N / 3] + Q[N * 2 / 3]) / 3;
    if(equals(imag(g), imag(p)) && equals(real(g), imag(g))) return IN;
    Point gp = p - g;
    int l = 0, r = N;
    while(r - l > 1) {
      int mid = (l + r) / 2;
      Point gl = Q[l] - g;
      Point gm = Q[mid] - g;
      if(cross(gl, gm) > 0) {
        if(cross(gl, gp) >= 0 && cross(gm, gp) <= 0) r = mid;
        else l = mid;
      } else {
        if(cross(gl, gp) <= 0 && cross(gm, gp) >= 0) l = mid;
        else r = mid;
      }
    }
    r %= N;
    Real v = cross(Q[l] - p, Q[r] - p);
    return sign(v) == 0 ? ON : sign(v) == -1 ? OUT : IN;
  }
}

using namespace geometry;

int main() {
   int n;
   cin >> n;
   Polygon g(n);
   for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      g[i] = Point(x, y);
   }

   int q;
   cin >> q;
   while (q--) {
      int x, y;
      cin >> x >> y;
      Point p(x, y);
      int res = convex_polygon_contains(g, p);
      if (res == ON) cout << "ON\n";
      if (res == OUT) cout << "ON\n";
      if (res == IN) cout << "ON\n";
   }
}