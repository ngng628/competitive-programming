# include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;
   const int n = s.length();
   int K;
   cin >> K;

   int ans = 0;
   int cnt = 0;
   for (int l = 0, r = 0; r < n; ++r) {
      cnt += 1;
      if (s[r] == '.') K--;

      while (K < 0) {
         if (s[l] == '.') K++;
         cnt -= 1;
         l++;
      }

      ans = max(ans, cnt);
   }

   cout << ans << '\n';
}