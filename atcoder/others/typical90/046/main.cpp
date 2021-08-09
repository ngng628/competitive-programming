# include <bits/stdc++.h>
# define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main() {
   int n;
   cin >> n;
   map<int, int> ma, mb, mc;
   rep (i, n) { int e; cin >> e; e %= 46; ma[e]++; }
   rep (i, n) { int e; cin >> e; e %= 46; mb[e]++; }
   rep (i, n) { int e; cin >> e; e %= 46; mc[e]++; }

   long long ans = 0;
   rep (i, 46 + 1) rep (k, 46 + 1) rep (m, 46 + 1) {
      if ((i + k + m) % 46 == 0) {
         ans += (long long) ma[i] * mb[k] * mc[m];
      }
   }

   cout << ans << '\n';
}