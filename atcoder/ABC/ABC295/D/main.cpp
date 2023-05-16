# include <bits/stdc++.h>
using namespace std;

int main() {
   string _s;
   cin >> _s;
   vector<int> s(_s.size());
   for (int i = 0; i < s.size(); i++) {
      s[i] = int(_s[i] - '0');
   }

   vector<array<int, 10>> csum(s.size() + 1);
   for (int i = 0; i < s.size(); i++) {
      for (int c = 0; c <= 9; c++) {
         if (i == 0) {
            csum[i][c] = 0;
         }
         csum[i + 1][c] = csum[i][c];
         if (s[i] == c) csum[i + 1][c] ^= 1;
      }
   }

   map<array<int, 10>, int> cnt;
   for (int i = 0; i < csum.size(); i++) {
      cnt[csum[i]] += 1;
   }

   long ans = 0;
   for (auto [key, value] : cnt) {
      ans += (long)value * (value - 1) / 2;
   }

   cout << ans << endl;
}