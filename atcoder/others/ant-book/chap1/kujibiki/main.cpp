# include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool Main() {
   int n, m;
   cin >> n >> m;
   if (!(n | m)) return false;
   vector<int> p(n);
   for_each(p.begin(), p.end(), [](int& e){ cin >> e; });
   p.push_back(0);
   n += 1;
   auto score = [&m](int sum) { return sum > m ? sum : sum; };

   vector<int> sums(n * n);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         sums[n*i + j] = p[i] + p[j];
      }
   }
   sort(sums.begin(), sums.end());

   int ans = 0;
   for (int s : sums) {
      if (m - s < 0) continue;
      auto it = upper_bound(sums.begin(), sums.end(), m - s) - 1;
      ans = max(ans, score(s + *it));
   }

   cout << ans << endl;
   return false;
}

int main() {
   while (Main());
}
