# include <bits/stdc++.h>
using namespace std;

struct Setup_io {
   Setup_io() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
      cout << fixed << setprecision(15);
   }
} setup_io;

int32_t main() {
   int N, Q;
   cin >> N >> Q;
   deque<int> a(N);
   for (int& e : a) cin >> e;
   while (Q--) {
      int t, x, y;
      cin >> t >> x >> y;
      x--, y--;
      if (t == 1) swap(a[x], a[y]);
      if (t == 2) {
         a.push_front(0);
         a[0] = a[N];
         a.pop_back();
      }
      if (t == 3) cout << a[x] << '\n';
   }
}