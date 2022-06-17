# include <bits/stdc++.h>
using namespace std;

int main() {
   vector<int> ans;
   for (int ratio = 1;; ratio *= 10) {
      for (int i = 1; i <= 99; ++i) {
         if (ratio * i >= 1000000) goto EXIT;
         ans.push_back(ratio * i);
      }
      ratio *= 10;
   }
   EXIT:

   cout << ans.size() << endl;
   for (size_t i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " \n"[i == ans.size() - 1];
   }
}