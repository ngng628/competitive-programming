# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n+2, 0);
   for (int i = 1; i <= n; ++i) cin >> a[i];

   vector<int> before(n+2, 0), after(n+2, 0);
   for (int i = 1; i <= n + 1; ++i) {
      before[i] = before[i-1] + abs(a[i] - a[i-1]);
      after[n-i+1] = after[n-i+2] + abs(a[n-i+1] - a[n-i+2]);
   }

   for (int i = 1; i <= n; ++i) {
      cout << before[i-1] + abs(a[i-1] - a[i+1]) + after[i+1] << "\n";
   }
}
