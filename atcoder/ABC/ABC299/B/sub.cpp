# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   cout << s << endl;

   int ans = -1;
   for (int i = 0; i < n; i++) {
      int j = i;
      cout << s[j] << endl;
      while (j < n && s[j] == 'o') {
         j += 1;
      }
      if (j < n - 1) ans = max(ans, j - i + 1);
      i = j;
   }

   reverse(s.begin(), s.end());
   for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && s[j] == 'o') {
         j += 1;
      }
      if (j < n - 1) ans = max(ans, j - i + 1);
      i = j;
   }

   cout << ans << endl;
}