# include <iostream>
# include <vector>
# include <set>
# include <map>
# include <utility>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <cassert>
# define rep (i, a, b) for (ll i = a; i < ll(b); i++)
# define all(v) std::begin(v), std::end(v)
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

template <ll MOD=998244353>
struct mint {
   ll v;
   mint(const ll x = 0) : v(((x % MOD) + MOD) % MOD) {}

   ll& val() { return v; }

   mint operator+(const mint b) const { return mint(*this) += b; }
   mint operator-(const mint b) const { return mint(*this) -= b; }
   mint operator*(const mint b) const { return mint(*this) *= b; }
   mint operator/(const mint b) const { return mint(*this) /= b; }

   mint& operator+=(const mint b) {
      v += b.v;
      if (v >= MOD) v -= MOD;
      return *this;
   }

   mint& operator-=(const mint b) {
      if (v < b.v) v += MOD;
      v -= b.v;
      return *this;
   }

   mint& operator*=(const mint b) {
      v = v * b.v % MOD;
      return *this;
   }

   mint& operator/=(const mint b) {
      return *this *= b.inv();
   }
   
   mint inv() const {
      return pow(MOD - 2);
   }
   
   mint pow(ll exp) const {
      mint ret(1);
      mint b = *this;
      while (exp) {
         if (exp % 2) ret *= b;
         b *= b;
         exp /= 2;
      }
      return ret;
   }
};

int main() {
   ll n;
   cin >> n;
   n *= 7;
   vector<ll> a(n);
   for (ll& ai :a )cin >> ai;
   for (int i = 0; i < n; i += 7) {
      ll sum = 0;
      for (int j = 0; j < 7; j++) {
         sum += a[i + j];
      }
      cout << sum << " ";
   }
   cout << endl;
}
