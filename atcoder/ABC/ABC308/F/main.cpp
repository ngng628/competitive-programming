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
   vector<ll> p(n), l(m), d(m);
   rep (i, 0, n) cin >> p[i];
   rep (i, 0, m) cin >> l[i];
   rep (i, 0, m) cin >> d[i];
   rep (i, 0, n + 1) {
      l.push_back(numeric_limits<ll>::max());
      d.push_back(0);
   }


   sort(all(p));
   vector<ll> ord(m);
   iota(all(ord), 0);
   sort(all(ord), [&](ll i, ll j) {
      if (l[i] == l[j]) {
         return d[i] > d[j];
      }
      else {
         return l[i] < l[j];
      }
   });
   vector l2 = l, d2 = d;
   rep (i, 0, m) {
      l2[i] = l[ord[i]];
      d2[i] = d[ord[i]];
   }

   swap(l, l2);
   swap(d, d2);

   ll ans = 0;
   int cur = 0;
      priority_queue<ll> heap;
   rep (i, 0, m) {
      ll j = i;
      while (j < m && l[i] == l[j]) {
         heap.push(d[j]);
         j++;
      }

      // ll begin = l[i];
      // ll end = l[j];

      while (cur < n && p[cur] < l[i]) {
         ans += p[cur++];
      }
      for (; cur < n && p[cur] <= l[j]; cur++) {
         if (not heap.empty()) {
            ll di = heap.top();
            heap.pop();
            ans += p[cur] - di;
         }
         else {
            break;
         }
      }


      i = j - 1;
   }

   while (cur < n) ans += p[cur++];

   cout << ans << endl;
}