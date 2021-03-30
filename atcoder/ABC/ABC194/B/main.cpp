# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n), b(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
   }

   int ans = numeric_limits<int>::max();
   for (int i = 0; i < n; ++i) {
      ans = min(ans, a[i] + b[i]);
      for (int j = i+1; j < n; ++j) {
         ans = min(ans, min(max(a[i], b[j]), max(a[j], b[i])));
      }
   }
   
   cout << ans << endl;
}