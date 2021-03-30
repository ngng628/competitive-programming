# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;

   vector<vector<long long>> v(10);
   v[1].insert(v[1].end(), {7, 5, 3});
   int ans = 0;
   for (int i = 2; i <= 9; ++i) {
      for (long long old : v[i-1]) {
         for (int m : {7, 5, 3}) {
            long long sft = 10LL*old + m;
            if (sft <= n) v[i].push_back(sft);
         }
      }
      if (i >= 3) ans += v[i].size();
   }

   for (int i = 3; i <= 9; ++i) {
      for (int sft : v[i]) {
         string s = to_string(sft);
         if (count(s.begin(), s.end(), '7') == 0) ans--;
         else if (count(s.begin(), s.end(), '5') == 0) ans--;
         else if (count(s.begin(), s.end(), '3') == 0) ans--;
      }
   }

   cout << ans << endl;
}