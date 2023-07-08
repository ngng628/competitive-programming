# include <bits/stdc++.h>
# define rep(i, a, b) for (ll i = a; i < ll(b); i++)
# define all(v) std::begin(v), std::end(v)
# define len(v) ll(std::size(v))
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

int main() {
   constexpr int inf = numeric_limits<int>::max();

   vector<int> a(8);
   rep (i, 0, 8) cin >> a[i];
   a.push_back(inf);

   vector<int> range(9);
   iota(all(range), 0);

   bool ok = all_of(all(range), [&](int i) {
      if (i == 8) return true;
      return a[i] <= a[i + 1] && 100 <= a[i] && a[i] <= 675 && a[i] % 25 == 0;
   });

   puts(ok ? "Yes" : "No");
}