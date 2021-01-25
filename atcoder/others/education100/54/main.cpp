# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> dp;
   for (int _ = 0; _ < n; ++_) {
      int c;
      cin >> c;
      auto it = lower_bound(dp.begin(), dp.end(), c);
      if (it != dp.end()) *it = c;
      else dp.push_back(c);
   }

   cout << n - dp.size() << "\n";
}
