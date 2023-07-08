# include <iostream>
# include <vector>
# include <set>
# include <map>
# include <utility>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <cassert>
# define rep(i, a, b) for (ll i = a; i < ll(b); i++)
# define all(v) std::begin(v), std::end(v)
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

struct Sheet {
   Sheet() = default;
   Sheet(int h, int w) : height(h), width(w), mat(h, vector<int>(w, 0)) {}
   Sheet(int h, int w, const vector<vector<int>>& s) : height(h), width(w), mat(s) {}
   int height, width;
   vector<vector<int>> mat;
};

int main() {
   Sheet a, b, x;
   auto input = [](Sheet& a) {
      int h, w; cin >> h >> w;
      vector s(h, vector<int>(w));
      rep (i, 0, h) {
         string buff; cin >> buff;
         rep (j, 0, w) s[i][j] = buff[j] == '#';
      }
      a = Sheet(h, w, s);
   };
   input(a), input(b), input(x);

   auto paste = [](Sheet& c, const Sheet& a, int si, int sj) -> bool {
      rep (i, 0, a.height) {
         rep (j, 0, a.width) {
            int ti = i + si, tj = j + sj;
            if (ti < 0 || ti >= c.height || tj < 0 || tj >= c.width) {
               if (a.mat[i][j] == 1) return false;
               continue;
            }
            c.mat[ti][tj] |= a.mat[i][j];
         }
      }
      return true;
   };

   rep (i1, -x.height - 1, x.height + 1) rep (j1, -x.width - 1, x.width + 1) {
      rep (i2, -x.height - 1, x.height + 1) rep (j2, -x.width - 1, x.width + 1) {
         Sheet c(x.height, x.width);
         if (not paste(c, a, i1, j1)) continue;
         if (not paste(c, b, i2, j2)) continue;
         if (c.mat == x.mat) {
            cout << "Yes" << endl;
            return 0;
         }
      }
   }
   cout << "No" << endl;
}