# include <bits/stdc++.h>
# include <atcoder/all>
using ll = long long;
using namespace std;
using namespace atcoder;

ll pow(ll x, ll p, ll mod) {
    ll ret = 1;
    while (p) {
        if (p & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ret;
}

ll sum(ll a, ll r, ll n, ll mod) {
    if (n == 1)
        return a % mod;

    ll x = sum(a, r, n/2, mod);
    ll ret = (x + pow(r, n/2, mod) * x) % mod;
    if (n & 1)
        ret = (a + r * ret) % mod;
    return ret;
}

int main() {
   ll a, x, m;
   cin >> a >> x >> m;

   if (a == 1) {
      cout << x % m << endl;
      return 0;
   }

   cout << sum(1, a, x, m) << endl;
}