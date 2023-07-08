# include <bits/stdc++.h>
# define rep(i, a, b) for (ll i = a; i < ll(b); i++)
# define all(v) std::begin(v), std::end(v)
# define len(v) ll(std::size(v))
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

int main() {
   int n;
   cin >> n;
   vector<ll> a(n), b(n);
   rep (i, 0, n) cin >> a[i] >> b[i];
   vector<int> ord(n, 0);
   iota(all(ord), 0);
   sort(ord.rbegin(), ord.rend(), [&](int i, int j){
      ll lhs = a[i] * (a[j] + b[j]);
      ll rhs = a[j] * (a[i] + b[i]);
      return make_pair(lhs, -i) < make_pair(rhs, -j);
   });
   rep (i, 0, n) {
      cout << ord[i] + 1 << " \n"[i == n - 1];
   }
}