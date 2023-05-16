# include <bits/stdc++.h>
using namespace std;

int main() {
   string _s;
   cin >> _s;
   vector<int> s(_s.size());
   for (int i = 0; i < s.size(); i++) {
      s[i] = int(_s[i] - '0');
   }
   sort(s.begin(), s.end());

   array<vector<int>, 10> csum;
   for (int i = 0; i <= 9; i++) {
      csum[i].resize(s.size() + 1);
      csum[i][0] = 0;
      for (int j = 0; j < s.size(); j++) {
         csum[i][j + 1] = csum[i][j];
         if (s[j] == i) {
            csum[i][j + 1]++;
         }
      }
   }

   for (int c = 0; c <= 9; c++) {
      for (int i = 0; i < s.size(); i++) {
         cout << csum[c][i] << " \n"[i == s.size() - 1];
      }
   }

   int ans = 0;
   for (int l = 0; l < s.size(); l++) {
      for (int r = l + 1; r <= s.size(); r++) {
         bool ok = true;
         for (int c = 0; c <= 9; c++) {
            if ((csum[c][r] - csum[c][l]) % 2 != 0) ok = false;
         }
         if (ok) {
            printf("[l, r] = [%d, %d]\n", l, r - 1);
            ans += 1;
         }
      }
   }

   cout << ans << endl;
}