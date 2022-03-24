# include <bits/stdc++.h>
# define int long long
using namespace std;
constexpr int MOD = 998244353;

int modpow(int a, int n, int mod) {
   int res = 1;
   while (n > 0) {
      if (n & 1) res = res * a % mod;
      a = a * a % mod;
      n >>= 1;
   }
   return res;
}

int32_t main() {
   int n, k;
   cin >> n >> k;
   if (k == 1) {
      cout << 1 << endl;
   }
   else if (k == 2) {
      if (n == 2 and k == 2) {
         cout << 3 << endl;
      }
      else {
         cout << n + 1 << endl;
      }
   }
   else {
      assert(k >= 3);
      if (n == 1) {
         cout << 2 << endl;
      }
      else if (n == 2) {
         cout << 4 << endl;
      }
      else {
         cout << modpow(2, n, MOD) << endl;
      }
   }
}