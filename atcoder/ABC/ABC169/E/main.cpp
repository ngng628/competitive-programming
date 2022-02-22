# include <bits/stdc++.h>
using namespace std;

int main() {
   size_t n;
   cin >> n;
   vector<int> a(n), b(n);
   for (size_t i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
   }

   sort(a.begin(), a.end());
   sort(b.begin(), b.end());

   int ans = [&]() {
      if (n & 1) {
         int low = a[n / 2];
         int up = b[n / 2];
         return up - low + 1;
      }
      else {
         int low = a[n / 2] + a[n / 2 - 1];
         int up = b[n / 2] + b[n / 2 - 1];
         return up - low + 1;
      }
   }();

   cout << ans << endl;
}
