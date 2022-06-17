# include <bits/extc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<pair<int, int>> ab(n);
   for (auto& [a, b] : ab) cin >> a >> b;
   sort(ab.begin(), ab.end(), [](pair<int, int> lhs, pair<int, int> rhs) {
      return lhs.second < rhs.second;
   });

   long long ela = 0;
   for (auto [a, b] : ab) {
      ela += a;
      if (ela > b) {
         cout << "No" << endl;
         return 0;
      }
   }

   cout << "Yes" << endl;
}