# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main() {
   int h, w;
   cin >> h >> w;
   vector a(h, vector<int>(w));
   for (auto& v : a) {
      for (auto& ai : v) {
         cin >> ai;
      }
   }

   vector<int> dir(h + w - 2, 1);
   for (int i = 0; i < w - 1; i++) {
      dir[i] = 0;
   }

   int ans = 0;
   do {
      vector<int> seq = { a[0][0] };
      int i = 0, j = 0;
      for (int d : dir) {
         if (d) i++;
         else j++;
         seq.push_back(a[i][j]);
      }
      if (seq.size() == set<int>(seq.begin(), seq.end()).size()) {
         ans++;
      }
   } while (next_permutation(dir.begin(), dir.end()));

   cout << ans << endl;
}