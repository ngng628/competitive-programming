# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<pair<string, int>> sp(n);
   for (int i = 0; i < n; i++) {
      cin >> sp[i].first >> sp[i].second;
   }

   vector<int> order(n);
   iota(order.begin(), order.end(), 0);
   sort(order.begin(), order.end(), [&](int i, int j) {
      if (sp[i].first == sp[j].first) {
         return sp[i].second > sp[j].second;
      }
      else {
         return sp[i].first < sp[j].first;
      }
   });

   for (auto i : order) {
      cout << i + 1 << "\n";
   }
}