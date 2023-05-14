# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   string s;
   cin >> s;

   int ans = -1;
   for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && s[j] == 'o') {
         j += 1;
      }
      if (j < n - 1 && i > 0) ans = max(ans, j - i);
      i = j;
   }

   reverse(s.begin(), s.end());
   for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && s[j] == 'o') {
         j += 1;
      }
      if (j < n - 1 && i > 0) ans = max(ans, j - i);
      i = j;
   }

   cout << ans << endl;
}