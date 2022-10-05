# include <bits/stdc++.h>
# define int long
using namespace std;

int32_t main() {
   constexpr int INF = (1L<<62)-(1L<<31);

   int n;
   cin >> n;

   int c1 = INF, b1 = -INF, a1 = 0;
   for (int i = 0; i < n; ++i) {
      int m, t;
      cin >> m >> t;

      int c2, b2, a2;
      if (t == 1) {
         c2 = INF; b2 = -INF; a2 = m;
      }
      else if (t == 2) {
         c2 = INF; b2 = m; a2 = 0;
      }
      else {
         c2 = m; b2 = -INF; a2 = 0;
      }

      int new_c = (c1 == INF ? c2 : min(c2, c1 + a2));
      int new_b = (b1 == -INF ? b2 : max(b2, b1 + a2));
      int new_a = a1 + a2;

      c1 = new_c;
      b1 = new_b;
      a1 = new_a;
   }

   auto f = [a1, b1, c1](int x) {
      return min(c1, max(b1, x + a1));
   };
   fprintf(stderr, "f(x) = min(%ld, max(%ld, x + %ld))\n", c1, b1, a1);

   int Q;
   cin >> Q;
   for (int q = 0; q < Q; ++q) {
      int x;
      cin >> x;
      cerr << "x = " << x << endl;
      cout << f(x) << endl;
   }
}