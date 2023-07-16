# include <bits/stdc++.h>
# define rep(i, a, b) for (ll i = a; i < ll(b); i++)
# define all(v) std::begin(v), std::end(v)
# define len(v) ll(std::size(v))
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

int main() {
   int n, m;
   cin >> n >> m;
   vector<string> c(n), d(m);
   for (string& ci : c) cin >> ci;
   for (string& di : d) cin >> di;
   vector<int> p(m + 1);
   for (int& pi : p) cin >> pi;

   map<string, int> mp;
   rep (i, 0, m) mp[d[i]] = p[i + 1];

   ll sum = 0;
   rep (i, 0, n) {
      if (mp.count(c[i])) sum += mp[c[i]];
      else sum += p[0];
   }

   cout << sum << endl;
}