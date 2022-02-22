# include <bits/stdc++.h>
using namespace std;

int main() {
   string n;
   cin >> n;
   sort(n.begin(), n.end());

   long ans = 0;
   do {
      for (size_t i = 1; i <= n.length() - 1; i++) {
         string a = n.substr(0, i);
         string b = n.substr(i);
         if (a[0] == '0' or b[0] == '0') continue;
         ans = max(ans, stol(a) * stol(b));
      }
   } while (next_permutation(n.begin(), n.end()));

   cout << ans << '\n';
}