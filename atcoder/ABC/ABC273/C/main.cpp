# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   scanf("%d", &n);
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }

   vector<int> b = a;
   sort(b.begin(), b.end());
   b.erase(unique(b.begin(), b.end()), b.end());

   vector<int> ans(n + 1, 0);
   for (int i = 0; i < n; i++) {
      int t = distance(upper_bound(b.begin(), b.end(), a[i]), b.end());
      ans[t] += 1;
   }

   for (int i = 0; i < n; i++) {
      printf("%d\n", ans[i]);
   }
}